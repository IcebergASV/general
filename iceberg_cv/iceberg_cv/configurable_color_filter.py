#Imports
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np

#Colour Filtering node
class ConfigurableColorFilter(Node):
    def __init__(self):
        super().__init__('configurable_color_filter')
        
        #Declare parameters with default values
        self.declare_parameters(
            namespace='',
            parameters=[
                ('input_topic', '/camera/image_raw'),
                ('output_topic', '/filtered_image'),
                ('lower_hsv', [35, 50, 50]),  # H, S, V
                ('upper_hsv', [85, 255, 255])
            ]
        )
        
        #Get parameter values
        self.input_topic = self.get_parameter('input_topic').value
        self.output_topic = self.get_parameter('output_topic').value
        self.lower_hsv = np.array(self.get_parameter('lower_hsv').value, dtype=np.int32)
        self.upper_hsv = np.array(self.get_parameter('upper_hsv').value, dtype=np.int32)
        
        self.bridge = CvBridge()
        
        #Create subscriber and publisher with configured topics
        self.sub = self.create_subscription(
            Image,
            self.input_topic,
            self.image_callback,
            10)
        
        self.pub = self.create_publisher(
            Image,
            self.output_topic,
            10)
        
        self.get_logger().info(f"""
        Color filter initialized with:
        Input topic: {self.input_topic}
        Output topic: {self.output_topic}
        HSV Range: {self.lower_hsv} to {self.upper_hsv}
        """)

    #Image processing callback
    def image_callback(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        except Exception as e:
            self.get_logger().error(f'Image conversion failed: {str(e)}')
            return

        hsv = cv2.cvtColor(cv_image, cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(hsv, self.lower_hsv, self.upper_hsv)
        
        #Create grayscale version and combine
        gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)
        gray_bgr = cv2.cvtColor(gray, cv2.COLOR_GRAY2BGR)
        
        filtered = cv2.bitwise_and(cv_image, cv_image, mask=mask) + \
                 cv2.bitwise_and(gray_bgr, gray_bgr, mask=cv2.bitwise_not(mask))

        try:
            self.pub.publish(self.bridge.cv2_to_imgmsg(filtered, 'bgr8'))
        except Exception as e:
            self.get_logger().error(f'Publishing failed: {str(e)}')

#Main function
def main(args=None):
    rclpy.init(args=args)
    node = ConfigurableColorFilter()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()