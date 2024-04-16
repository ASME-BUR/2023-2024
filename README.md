
# Bruin Underwater Robotics (2023-2024)
2023-2024 repository for ASME @ UCLA's Bruin Underwater Robotics Team

All completed code goes here


## Run Instructions
To run as an ROV, run: 

1. On laptop:

   i. Run Joy nodes: `src-ros2 & ros2 launch bur_rov joy.launch.py`

2. On Pi (via SSH - `ssh ubuntu@[IP ADDRESS]`):

   i. Run micro-ros-agent nodes [IMU, Arduino]: `ros2 launch bur_rov micro_ros.launch.py`

   ii. Run PID & thruster manager nodes: `ros2 launch bur_rov rov.launch.py`

### Micro-Ros-Agent
To Run Micro-Ros-Agent do:

```
ros2 run micro_ros_agent micro_ros_agent serial --dev /dev/ttyACM0
```

- Serial indicates the transport type
- --dev is the port

### ZED
To start the ZED ROS Node, run:

```sh
ros2 launch zed_wrapper zed_camera.launch.py camera_model:=zedm
```
