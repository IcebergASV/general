from setuptools import find_packages
from setuptools import setup

setup(
    name='comp_tasks_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('comp_tasks_interfaces', 'comp_tasks_interfaces.*')),
)
