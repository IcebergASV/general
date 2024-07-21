import rclpy
from rclpy.node import Node
from mavros_msgs.msg import State
import gpiod

#pinout for pi:https://www.etechnophiles.com/raspberry-pi-4-gpio-pinout-specifications-and-schematic/
class LedController():
    #Adding the line values from the RasberryPI model sheet and the command in the terminal: gpioinfo gpiochip0
    #Output Pins for the LED Tower
    RED_LED_LINE = 27 #gpio32 on jetson
    YELLOW_LED_LINE = 22 #gpio27 on jetson
    GREEN_LED_LINE = 5 #gpio8 on jetson

    KILL_SWITCH_LINE = 17 #This will be an input pin. It needs to be able to sustain the voltage being given to it. Pin 17, 22, or 25 should work fine #gpio35 on jetson
    def __init__(self):
        chip = gpiod.Chip('/dev/gpiochip0') #This is an important step so that the correct pins are chosen

        #Gets the addresses of the line
        self._red_line = chip.get_line(LedController.RED_LED_LINE)
        self._yellow_line = chip.get_line(LedController.YELLOW_LED_LINE)
        self._green_line = chip.get_line(LedController.GREEN_LED_LINE)

        self._kill_switch_line = chip.get_line(LedController.KILL_SWITCH_LINE)

        #Sets the direction of the pin: gpiod.LINE_REQ_DIR_OUT is output and gpiod.LINE_REQ_DIR_IN is input.
        #Consumer Name can be anything
        self._red_line.request(consumer='red_led_light',type=gpiod.LINE_REQ_DIR_OUT)
        self._yellow_line.request(consumer='yellow_led_light',type=gpiod.LINE_REQ_DIR_OUT)
        self._green_line.request(consumer='green_led_light',type=gpiod.LINE_REQ_DIR_OUT)

        self._kill_switch_line.request(consumer='kill_switch_input',type=gpiod.LINE_REQ_DIR_IN)
        
        self._red_line.set_value(0)
        self._green_line.set_value(0)
        self._yellow_line.set_value(0)

    def led_tower_control(self, guided_mode):
        kill_switch_activated = (self._kill_switch_line.get_value() == 1) #Checks 
        print(self._red_line.get_value())
        print(self._yellow_line.get_value())
        print(self._green_line.get_value())
        if kill_switch_activated:
            self._yellow_line.set_value(0)
            self._green_line.set_value(0)
            self._red_line.set_value(1)
        elif guided_mode:
            self._red_line.set_value(0)
            self._yellow_line.set_value(0)
            self._green_line.set_value(1)
        else:
            self._red_line.set_value(0)
            self._green_line.set_value(0)
            self._yellow_line.set_value(1)

    def __del__(self):
        self._red_line.set_value(0)
        self._green_line.set_value(0)
        self._yellow_line.set_value(0)
        
        self._red_line.release()
        self._yellow_line.release()
        self._green_line.release()
        self._kill_switch_line.release()


class MavrosStateSubscriber(Node):

    def __init__(self):
        super().__init__('mavros_state_subscriber')
        self.subscription = self.create_subscription(
            State,
            '/mavros/state',
            self.state_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.led_tower = LedController()

    def state_callback(self, msg):
        guided = msg.guided
        self.led_tower.led_tower_control(guided)
        self.get_logger().info(f'Autonomous: {guided}')

def main(args=None):
    rclpy.init(args=args)

    mavros_state_subscriber = MavrosStateSubscriber()

    rclpy.spin(mavros_state_subscriber)

    # Destroy the node explicitly
    mavros_state_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
