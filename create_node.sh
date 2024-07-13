#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <package_name> <class_name> <node_name>"
    exit 1
fi

# Extract arguments
PACKAGE_NAME=$1
CLASS_NAME=$2
NODE_NAME=$3

# Directories
SRC_DIR="${PACKAGE_NAME}/src"
INCLUDE_DIR="${PACKAGE_NAME}/include/${PACKAGE_NAME}"

# Filenames
CPP_FILE="${SRC_DIR}/${NODE_NAME}_component.cpp"
COMPOSITION_FILE="${SRC_DIR}/${NODE_NAME}_composition.cpp"
HEADER_FILE="${INCLUDE_DIR}/${NODE_NAME}_component.hpp"
CMAKE_FILE="${PACKAGE_NAME}/CMakeLists.txt"

# Create the src and include directories if they don"t exist
mkdir -p $SRC_DIR
mkdir -p $INCLUDE_DIR

# Create the component.cpp file
cat <<EOL > $CPP_FILE
#include "${PACKAGE_NAME}/${NODE_NAME}_component.hpp"

namespace ${PACKAGE_NAME}
{
  ${CLASS_NAME}::${CLASS_NAME}(const rclcpp::NodeOptions & options)
  : Node("${NODE_NAME}", options)
  {
    example_sub_ = this->create_subscription<std_msgs::msg::Int32>("/${PACKAGE_NAME}/subscribing_topic", 10, std::bind(&${CLASS_NAME}::callback, this, _1));
    example_pub_ = this->create_publisher<std_msgs::msg::Float64>("${PACKAGE_NAME}/publishing_topic", 10);

    ${CLASS_NAME}::getParam<int>("multiplier", p_multiplier_, 0, "Multiplies number by this integer");
    ${CLASS_NAME}::getParam<double>("adder", p_adder_, 0, "Adds this double to a number");
    on_set_parameters_callback_handle_ = this->add_on_set_parameters_callback(std::bind(&${CLASS_NAME}::param_callback, this, std::placeholders::_1));
  }

  rcl_interfaces::msg::SetParametersResult ${CLASS_NAME}::param_callback(const std::vector<rclcpp::Parameter> &params)
  {
    rcl_interfaces::msg::SetParametersResult result;

    if (params[0].get_name() == "multiplier") { p_multiplier_ = params[0].as_int(); }
    else if (params[0].get_name() == "adder") { p_adder_ = params[0].as_double(); }
    else {
      RCLCPP_ERROR(this->get_logger(), "Invalid Param");
      result.successful = false;
      return result;
    }

    result.successful = true;
    return result;
  }

  void ${CLASS_NAME}::callback(const std_msgs::msg::Int32::SharedPtr msg)
  {
    std_msgs::msg::Float64 new_value;
    new_value.data = msg->data *p_multiplier_ + p_adder_;

    example_pub_->publish(new_value);
  }
}
#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(${PACKAGE_NAME}::${CLASS_NAME})
EOL

# Create the .hpp file
cat <<EOL > $HEADER_FILE
#ifndef ${NODE_NAME}_HPP
#define ${NODE_NAME}_HPP

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/float64.hpp>

using std::placeholders::_1;

namespace ${PACKAGE_NAME}
{

class ${CLASS_NAME} : public rclcpp::Node
{
public:
    explicit ${CLASS_NAME}(const rclcpp::NodeOptions & options);

private:
    void callback(const std_msgs::msg::Int32::SharedPtr msg);
    rcl_interfaces::msg::SetParametersResult param_callback(const std::vector<rclcpp::Parameter> &params);

    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr example_sub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr example_pub_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr on_set_parameters_callback_handle_;

    int p_multiplier_;
    double p_adder_;

    template <typename T>
    void getParam(std::string param_name, T& param, T default_value, std::string desc)
    {
      auto param_desc = rcl_interfaces::msg::ParameterDescriptor{};
      param_desc.description = desc;
      this->declare_parameter<T>(param_name, default_value, param_desc);
      this->get_parameter(param_name, param);
      std::string param_log_output = param_name + ": " + std::to_string(param);
      RCLCPP_INFO(this->get_logger(), param_log_output.c_str()); 

      return;
    }
};

} // namespace ${PACKAGE_NAME}

#endif // ${NODE_NAME}_HPP
EOL

# Create the composition.cpp file
cat <<EOL > $COMPOSITION_FILE
#include <memory>

#include "${PACKAGE_NAME}/${NODE_NAME}_component.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) 
{
  setvbuf(stdout, NULL, _IONBF, BUFSIZ); // log messages immediately instead of buffering

  rclcpp::init(argc, argv);

  rclcpp::executors::SingleThreadedExecutor exec;
  rclcpp::NodeOptions options;

  auto ${NODE_NAME} = std::make_shared<${PACKAGE_NAME}::${CLASS_NAME}>(options);
  
  exec.add_node(${NODE_NAME});
  exec.spin();

  rclcpp::shutdown();

  return 0;
}
EOL

# Add the executable to the CMakeLists.txt
if ! grep -q "add_library(${NODE_NAME}_component" $CMAKE_FILE; then
    echo -e "add_library(${NODE_NAME}_component SHARED src/${NODE_NAME}_component.cpp)" >> $CMAKE_FILE
    echo "target_compile_definitions(${NODE_NAME}_component PRIVATE \"COMPOSITION_BUILDING_DLL\")" >> $CMAKE_FILE
    echo "ament_target_dependencies(${NODE_NAME}_component" >> $CMAKE_FILE
    echo "  \"rclcpp\"" >> $CMAKE_FILE
    echo "  \"rclcpp_components\"" >> $CMAKE_FILE
    echo "  \"std_msgs\")" >> $CMAKE_FILE
    echo "rclcpp_components_register_nodes(${NODE_NAME}_component \"${PACKAGE_NAME}::${CLASS_NAME}\")" >> $CMAKE_FILE
    echo "set(node_plugins \"${node_plugins}${PACKAGE_NAME}::${CLASS_NAME};$<TARGET_FILE:${NODE_NAME}_component>\n\")" >> $CMAKE_FILE
fi

if ! grep -q "add_executable(${NODE_NAME}" $CMAKE_FILE; then
    echo "install(TARGETS" >> $CMAKE_FILE
    echo "  ${NODE_NAME}_component" >> $CMAKE_FILE
    echo "  ARCHIVE DESTINATION lib" >> $CMAKE_FILE
    echo "  LIBRARY DESTINATION lib" >> $CMAKE_FILE
    echo "  RUNTIME DESTINATION bin)" >> $CMAKE_FILE
    echo -e "\n# Add executable for ${NODE_NAME}" >> $CMAKE_FILE
    echo "add_executable(${NODE_NAME}_composition" >> $CMAKE_FILE
    echo "  src/${NODE_NAME}_composition.cpp)" >> $CMAKE_FILE
    echo "target_link_libraries(${NODE_NAME}_composition" >> $CMAKE_FILE
    echo "${NODE_NAME}_component)" >> $CMAKE_FILE
    echo "ament_target_dependencies(${NODE_NAME}_composition" >> $CMAKE_FILE
    echo "  rclcpp)" >> $CMAKE_FILE
    echo "install(TARGETS" >> $CMAKE_FILE
    echo "  ${NODE_NAME}_composition" >> $CMAKE_FILE
    echo "  DESTINATION lib/\${PROJECT_NAME})" >> $CMAKE_FILE 
fi
