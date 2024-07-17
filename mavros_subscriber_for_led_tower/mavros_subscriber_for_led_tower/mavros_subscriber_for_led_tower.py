import rclpy
from rclpy.node import Node
from mavros_msgs.msg import State

class MavrosStateSubscriber(Node):

    def __init__(self):
        super().__init__('mavros_state_subscriber')
        self.subscription = self.create_subscription(
            State,
            '/mavros/state',
            self.state_callback,
            10)
        self.subscription  # prevent unused variable warning

    def state_callback(self, msg):
        guided = msg.guided
        self.get_logger().info(f'Guided: {guided}')

def main(args=None):
    rclpy.init(args=args)

    mavros_state_subscriber = MavrosStateSubscriber()

    rclpy.spin(mavros_state_subscriber)

    # Destroy the node explicitly
    mavros_state_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
