from setuptools import find_packages
from setuptools import setup

setup(
    name='zed_interfaces',
    version='4.0.0',
    packages=find_packages(
        include=('zed_interfaces', 'zed_interfaces.*')),
)
