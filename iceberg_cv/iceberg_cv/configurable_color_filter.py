#Imports
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np

#Random class ID on startup
import random

#Import your YOLOv8 custom message type (replace with actual type)
from yolov8_msgs.msg import IcebergDetection, IcebergDetectionArray, IcebergBoundingBox2D

#Colour Filtering node
class ConfigurableColorFilter(Node):
    def __init__(self):
        super().__init__('configurable_color_filter')

        #Class IDs are not being used yet
        self.class_id = random.getrandbits(32)
        
        #Declare parameters with default values
        self.declare_parameters(
            namespace='',
            parameters=[
                ('input_img_topic', '/camera/camera/color/image_raw'),
                ('output_img_topic', '/icebergcv/filtered_image'),
                ('output_det_topic', '/icebergcv/detections'),
                ('output_class_name', 'green'),
                ('min_area', 50),
                ('lower_hsv', [35, 50, 50]),  #H, S, V
                ('upper_hsv', [85, 255, 255])
            ]
        )
        
        #Get parameter values
        self.input_topic = self.get_parameter('input_img_topic').value
        self.output_topic = self.get_parameter('output_img_topic').value
        self.output_detections_topic = self.get_parameter('output_det_topic').value
        self.class_name = self.get_parameter('output_class_name').value
        self.min_area = self.get_parameter('min_area').value
        self.lower_hsv = np.array(self.get_parameter('lower_hsv').value, dtype=np.int32)
        self.upper_hsv = np.array(self.get_parameter('upper_hsv').value, dtype=np.int32)
        
        self.bridge = CvBridge()
        
        #Create subscriber and publisher with configured topics
        self.sub = self.create_subscription(Image, self.input_topic, self.image_callback, 10)
        
        self.imgpub = self.create_publisher(Image, self.output_img_topic, 10)
        self.detpub = self.create_publisher(Image, self.output_detections_topic, 10)
        
        self.get_logger().info(f"""Color filter initialized with:
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

        #Image retrieved from cv bridge
        hsv = cv2.cvtColor(cv_image, cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(hsv, self.lower_hsv, self.upper_hsv)
        
        #Create grayscale version and combine
        gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)
        gray_bgr = cv2.cvtColor(gray, cv2.COLOR_GRAY2BGR)
        
        #Get the filtered image
        filtered = cv2.bitwise_and(cv_image, cv_image, mask = mask) + \
                 cv2.bitwise_and(gray_bgr, gray_bgr, mask = cv2.bitwise_not(mask))

        #Get countours for bounding box detections
        contours, __unused = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        # Prepare bounding box message
        det_array = IcebergDetectionArray()
        det_array.header = msg.header

        detection_list = []

        #Iterate through contours, if they fufill the specified area requirements we have a detection
        for cnt in contours:
            if cv2.contourArea(cnt) > self.min_area:
                x, y, w, h = cv2.boundingRect(cnt)
                
                # Draw bounding box
                cv2.rectangle(filtered, (x, y), (x + w, y + h), (0, 255, 0), 2)
                
                # Create BoundingBox2D message
                bboxD = IcebergBoundingBox2D(xmin = x, ymin = y, xmax = x + w, ymax = y + h)
                
                #Fill out detection statistics, class name, and bounding box
                det = IcebergDetection(class_id = 100, class_name = self.class_name, score = 1.00, bbox = bboxD)
                detection_list.append(det)

        #Add the detections to the list
        detection_list.icebergdetections = detection_list

        #Attempt to publish the required topics
        try:
            self.imgpub.publish(self.bridge.cv2_to_imgmsg(filtered, 'bgr8'))
            self.detpub.publish(detection_list)
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