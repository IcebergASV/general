# general

## Building

	cd ros2_ws/
	rosdep install -i --from-path src --rosdistro humble -y
	colcon build --symlink-install