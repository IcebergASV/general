import rclpy
from rclpy.node import Node
from mavros_msgs.msg import State
import gpiod

#To build the code use: colcon build --packages-select mavros_subscriber_for_led_tower
#Don't forget to do: source install/setup.bash 
#To run the code use: ros2 run mavros_subscriber_for_led_tower listner


#pinout for pi:https://www.etechnophiles.com/raspberry-pi-4-gpio-pinout-specifications-and-schematic/

#The LedController Class is used for communication with the RasberryPI GPIO pins 27, 22, 5, and 17. Those pins can be changed by changing the class variables *_LINE
class LedController():
    #Adding the line values from the RasberryPI model sheet and the command in the terminal: gpioinfo gpiochip0
    #Output Pins for the LED Tower
    RED_LED_LINE = 27 #gpio27
    YELLOW_LED_LINE = 22 #gpio22
    GREEN_LED_LINE = 5 #gpio5

    KILL_SWITCH_LINE = 17 #This will be an input pin. It needs to be able to sustain the voltage being given to it (3.3V in this case). Pin 17, 22, or 25 should work fine gpio17 is being used.
    
    #Setup the GPIO Pins upon start of the program
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
        
        #Turn off all the lights in the tower
        self._red_line.set_value(0)
        self._green_line.set_value(0)
        self._yellow_line.set_value(0)

    def led_tower_control(self, guided_mode):
        kill_switch_activated = (self._kill_switch_line.get_value() == 0) #The kill switch opens the circuit.
                                                                            #When no current is passing to the input pin, it reads 0.
        
        #print statements that can help in debugging (ONLY USE IT FOR DEBUGING)\/
        #print("RED LED:", self._red_line.get_value())
        #print("YELLOW LED:", self._yellow_line.get_value())
        #print("GREEN LED: ", self._green_line.get_value())
        
        if kill_switch_activated:
            self._yellow_line.set_value(0)
            self._green_line.set_value(0)
            self._red_line.set_value(1)
        elif guided_mode: #Guided mode is autonomous mode
            self._red_line.set_value(0)
            self._yellow_line.set_value(0)
            self._green_line.set_value(1)
        else: #If the kill switch is not on and the boat is not in guided mode, it must be in Manual mode (RC mode)!!
            self._red_line.set_value(0)
            self._green_line.set_value(0)
            self._yellow_line.set_value(1)

    #Upon termination of the program, turn off all the lights, and release all the pins
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
        self.led_tower = LedController() #Instantiate the LED tower controller to set the GPIOs

    def state_callback(self, msg):
        guided = msg.guided #Get the value of guided
        self.led_tower.led_tower_control(guided) #pass that to the led tower so that it sets the LED light properly

        #print statement that can help in debugging (ONLY USE IT FOR DEBUGING)\/
        #self.get_logger().info(f'Autonomous: {guided}')

def main(args=None):
    try: #Stop the coe gracefully when CTRL+C is clicked. Otherwise the keyboardinterrupt error will show up
        rclpy.init(args=args)

        mavros_state_subscriber = MavrosStateSubscriber()

        rclpy.spin(mavros_state_subscriber)
    except:
        # Destroy the node
        mavros_state_subscriber.destroy_node()

if __name__ == '__main__':
    main()
