
# Bruin Underwater Robotics (2023-2024)
2023-2024 repository for ASME @ UCLA's Bruin Underwater Robotics Team

## Dependencies
Requires Ubuntu 22.04 + ROS2 Humble

Package dependencies:
- `controller`: `ros-<DISTRO>-control-toolbox`
- `eskf`: `ros-<DISTRO>-robot-localization`, `ros-<DISTRO>-mavros`
- `bur_auv`: `ros-<DISTRO>-navigation2`, `ros-<DISTRO>-behaviortree-cpp`
- `usb_camera_driver`: `ros-<DISTRO>-image-common`
- `drivers`: `pigpio`; see https://github.com/joan2937/pigpio/tree/master

This project contains the following Git submodules: 
- https://github.com/ASME-BUR/bur_rov_msgs
- https://github.com/micro-ROS/micro_ros_setup
- https://github.com/ptrmu/ros2_shared
- https://github.com/klintan/ros2_usb_camera

## Build Instructions
To build all packages: 
1. Install all dependencies: `sudo apt-get install <DEPENDENCIES>`

   i. Follow the instructions at https://github.com/joan2937/pigpio/tree/master for installing `pigpio`
3. Clone this repository: `git clone https://github.com/ASME-BUR/2023-2024.git`
4. Initialize Git submodules: `cd 2023-2024 && git submodule init && git submodule update`
5. Build ROS packages: `cd ros2_ws && colcon build --symlink-install`

## Run Instructions
To run as an AUV, run:
1. On Raspberry Pi (via SSH):

   i. Launch ROS nodes: `ros2 launch bur_rov rov.launch.py`
3. On Jetson Orin (via SSH):

   i. Launch ZED node: `ros2 launch bur_vision zed.launch.py`

   ii. Run YOLO: `ros2 run yolo yolo`

### Micro-Ros-Agent
To Run Micro-Ros-Agent separately, enter:

```
ros2 run micro_ros_agent micro_ros_agent serial --dev /dev/ttyACM0
```

- Serial indicates the transport type
- --dev is the port
