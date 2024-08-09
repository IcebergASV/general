# general

## Packages
### [laser_segmentation](https://github.com/IcebergASV/general/tree/main/laser_segmentation)

Groups LiDAR data into segments and publishes segment array.


## Building

	cd ros2_ws/
	rosdep install -i --from-path src --rosdistro humble -y
	colcon build --symlink-install

 
## [mavros_subscriber_for_led_tower](https://github.com/IcebergASV/general/tree/fk-led-tower/mavros_subscriber_for_led_tower)

The package that listens to mavros topic and changes the led tower light from the RasberryPi GPIO pins.

## The RasberryPi password: rasberry

## NOTE: The Pi has to be connected to the Jetson through LAN and be pinging to be able to listen to the mavros topic. Mavros has to be running on the Jetson as well.
## Building
	cd ros2_ws/
	colcon build --packages-select mavros_subscriber_for_led_tower
 	source install/setup.bash
 	ros2 run mavros_subscriber_for_led_tower listner

## PI GPIO Pinout
![PI GPIO Pinout](https://images.app.goo.gl/ttdA4ZrtSoVLN1jW9)

### Pinout Connections for LED Tower

- Pin 13 (GPIO27) is for red
- Pin 15 (GPIO22) is for yellow
- Pin 29 (GPIO05) is for green
- Pin 11 (GPIO17) is for the input of the kill switch
