
---

## File: `global_to_local.cpp`

### Purpose

ROS 2 node that converts **global GPS waypoints (latitude, longitude, altitude)** into **local ENU coordinates** using a MAVROS-provided GPS reference origin.

### Class: `GlobalToLocalConverter`

Inherits from `rclcpp::Node`.

#### Constructor

```cpp
GlobalToLocalConverter();
```

**Behavior**

* Initializes the node with name `"global_to_local_converter"`.
* Configures sensor-data QoS.
* Initializes a `GeographicLib::LocalCartesian` ENU converter with a default reference.
* Creates:

  * Subscriber to global setpoints.
  * Subscriber to GPS reference origin.
  * Publisher for local ENU poses.

---

#### Method: `globalCallback`

```cpp
void globalCallback(
  const geographic_msgs::msg::GeoPoseStamped::SharedPtr msg
);
```

**Arguments**

* `msg`: Global pose message containing:

  * `latitude`
  * `longitude`
  * `altitude`
  * `orientation`

**Behavior**

* Converts GPS coordinates to ENU `(x, y, z)` using the current reference.
* Publishes a `geometry_msgs::msg::PoseStamped` in the `"map"` frame.
* Preserves orientation from the input message.

---

#### Method: `refCallback`

```cpp
void refCallback(
  const geographic_msgs::msg::GeoPointStamped::SharedPtr msg
);
```

**Arguments**

* `msg`: GPS reference origin containing latitude, longitude, altitude.

**Behavior**

* Updates ENU reference origin.
* Calls `LocalCartesian::Reset`.
* Unsubscribes after first valid reference fix.

---

#### Function: `main`

```cpp
int main(int argc, char ** argv);
```

**Arguments**

* `argc`: Argument count.
* `argv`: Argument vector.

**Behavior**

* Initializes ROS 2.
* Spins `GlobalToLocalConverter`.
* Shuts down ROS on exit.

---

## File: `local_to_global.cpp`

### Purpose

Converts **local ENU waypoints** into **global GPS coordinates** and exports them as CSV route files.

### Class: `LocalToGlobalConverter`

Inherits from `rclcpp::Node`.

#### Constructor

```cpp
LocalToGlobalConverter();
```

**Behavior**

* Initializes node `"local_to_global_converter"`.
* Configures ENU converter.
* Subscribes to:

  * Waypoint group messages.
  * GPS reference origin.
* Publishes converted GPS waypoints.

---

#### Method: `wpGroupCallback`

```cpp
void wpGroupCallback(
  const comp_tasks_interfaces::msg::WpGroupInfo::SharedPtr msg
);
```

**Arguments**

* `msg`: Waypoint group message containing:

  * `group_name`
  * `current_pose_local`
  * Vector of waypoints `wps`

**Behavior**

* Creates a `routes/` directory if missing.
* Generates two CSV files:

  * Global GPS coordinates.
  * Local ENU coordinates.
* Converts ENU → GPS using `LocalCartesian::Reverse`.
* Filenames are timestamped and sanitized.

---

#### Method: `refCallback`

```cpp
void refCallback(
  const geographic_msgs::msg::GeoPointStamped::SharedPtr msg
);
```

**Arguments**

* `msg`: Reference GPS origin.

**Behavior**

* Sets ENU reference.
* Resets the converter.
* Unsubscribes after first message.

---

#### Function: `main`

```cpp
int main(int argc, char ** argv);
```

**Arguments**

* `argc`: Argument count.
* `argv`: Argument vector.

**Behavior**

* Initializes ROS 2.
* Spins `LocalToGlobalConverter`.
* Cleans up on shutdown.

---

## File: `mavros_repub_component.cpp`

### Purpose

ROS 2 **component node** that repackages MAVROS flight mode state into a simple boolean guided-status topic.

### Namespace

```cpp
namespace comp_tasks
```

### Class: `MavROSRepublisher`

Inherits from `rclcpp::Node`.

#### Constructor

```cpp
MavROSRepublisher(const rclcpp::NodeOptions & options);
```

**Arguments**

* `options`: Node configuration options for component loading.

**Behavior**

* Subscribes to `/mavros/state`.
* Publishes `/guided_status` as `std_msgs::msg::Bool`.

---

#### Method: `republishMAVROSStatus`

```cpp
void republishMAVROSStatus(
  const mavros_msgs::msg::State::SharedPtr msg
);
```

**Arguments**

* `msg`: MAVROS state message containing:

  * `mode`
  * arming and connection status

**Behavior**

* Sets output `true` if mode is `"GUIDED"` or `"AUTO"` (ArduPilot).
* Publishes simplified guided status.
* Logs debug output.

---

#### Component Registration

```cpp
RCLCPP_COMPONENTS_REGISTER_NODE(comp_tasks::MavROSRepublisher);
```

Registers the node for dynamic composition.

---

## File: `mavros_repub_main.cpp`

### Purpose

Standalone executable wrapper for running `MavROSRepublisher` without composition.

---

#### Function: `main`

```cpp
int main(int argc, char *argv[]);
```

**Arguments**

* `argc`: Argument count.
* `argv`: Argument vector.

**Behavior**

* Disables stdout buffering for immediate logs.
* Initializes ROS 2.
* Creates a single-threaded executor.
* Spins `MavROSRepublisher`.
* Shuts down ROS on exit.

---
