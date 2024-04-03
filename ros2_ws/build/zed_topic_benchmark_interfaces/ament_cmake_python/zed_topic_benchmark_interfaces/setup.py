from setuptools import find_packages
from setuptools import setup

setup(
    name='zed_topic_benchmark_interfaces',
    version='4.0.0',
    packages=find_packages(
        include=('zed_topic_benchmark_interfaces', 'zed_topic_benchmark_interfaces.*')),
)
