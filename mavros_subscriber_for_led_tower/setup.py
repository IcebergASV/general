from setuptools import setup

package_name = 'mavros_subscriber_for_led_tower'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'gpiod'],
    zip_safe=True,
    maintainer='Fares Khalil',
    maintainer_email='faakhalil@mun.ca',
    description='ROS2 package to subscribe to mavros state',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'listner = mavros_subscriber_for_led_tower.mavros_subscriber_for_led_tower:main'
        ],
    },
)