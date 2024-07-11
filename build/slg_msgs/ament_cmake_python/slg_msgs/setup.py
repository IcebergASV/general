from setuptools import find_packages
from setuptools import setup

setup(
    name='slg_msgs',
    version='3.8.0',
    packages=find_packages(
        include=('slg_msgs', 'slg_msgs.*')),
)
