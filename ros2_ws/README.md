# System #

- Ubuntu 20.04
- ROS2 Foxy
- Gazebo 11

# Wiki #

#### Check the [wiki](https://git.whoi.edu/mural/muuv_tests/ros2_ws/-/wikis/home) for more info on packages ####

# Installation #

### 1. If you don’t have ROS 2 Foxy installed ###
Follow the instructions below and install the `ros-foxy-desktop` package: 
   <https://index.ros.org/doc/ros2/Installation/Foxy/Linux-Install-Debians/>

### 2. If you don’t have Pigpio installed ### 
Follow the instructions below:
   <https://abyz.me.uk/rpi/pigpio/download.html>

### 3. Install Gazebo: ###

   ```
   sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-stable `lsb_release -cs` main" > /etc/apt/sources.list.d/gazebo-stable.list'
   wget https://packages.osrfoundation.org/gazebo.key -O - | sudo apt-key add -
   sudo apt-get update
   sudo apt-get install gazebo11
   sudo apt-get install libgazebo11-dev
   ```
   You can write gazebo in a terminal to make sure that gazebo runs correctly. Write gazebo --version to ensure that the version number is 11.X.

### 4. Install the ros packages for gazebo: ###
   ```
   sudo apt install ros-foxy-gazebo-ros-pkgs
   ```

### 5. Clone this repository with: ###

   ```
   git clone --recurse-submodules https://git.whoi.edu/mural/muuv_tests/ros2_ws.git
   ```

### 6. Put all these commands into your ~/.bashrc: ###

   ```
   echo "source /opt/ros/foxy/setup.bash
   cd ~/ros2_ws
   source install/setup.bash
   source /usr/share/colcon_cd/function/colcon_cd.sh
   export _colcon_cd_root=/opt/ros/foxy/
   source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash
   source /usr/share/gazebo/setup.sh
   export LIBGL_ALWAYS_SOFTWARE=1" >> ~/.bashrc
   ```
   For WSL users, include this line as well:
   ```
   export QT_QPA_PLATFORMTHEME=qt5ct
   ```
   I like to create an alias (if you have multiple ROS distros).
   Just type "src-ros2" when you open a new terminal.
   ```
   echo "alias src-ros2='source /opt/ros/foxy/setup.bash && cd ~/ros2_ws && source install/setup.bash && source /usr/share/colcon_cd/function/colcon_cd.sh && export _colcon_cd_root=/opt/ros/foxy/ && source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash && source /usr/share/gazebo/setup.sh && export LIBGL_ALWAYS_SOFTWARE=1 && export QT_QPA_PLATFORMTHEME=qt5ct'" >> ~/.bashrc
   ```
   ** The source /opt/ros/foxy/setup.bash file sources all your ros packages installed in /opt
   ** The source install/setup.bash file sources all your packages in your ws. If colcon cant find a package (this happens the first time after you build a package), resourcing these files usually works

### 7. In order to download missing packages, install ROS dependency manager. ###
Write the commands below in a terminal:

   ```
   sudo apt install python3-rosdep
   sudo rosdep init
   rosdep update
   ```
   Browse to the root of your workspace and check for missing dependencies:

   ```
   cd ~/ros2_ws/
   rosdep install -i --from-path src --rosdistro foxy -y
   ```

   If rosdep is having trouble installing packages, you can also install them manually using:
   ```
   sudo apt install ros-foxy-<PACKAGE_NAME>
   ```
   Notable ones are:
   ```
   sudo apt install ros-foxy-control-toolbox ros-foxy-joy-teleop ros-foxy-xacro ros-foxy-joint-state-publisher
   ```
### 8. Install Colcon, the build tool system: ###
   ```
   sudo apt install python3-colcon-common-extensions
   ```

### 9. Build packages in ros2_ws: ###
   ```
   colcon build
   ```
   * Some of these packages are very big so it might take a couple builds
   * You can also build a specific package:
      ```
      colcon build --packages-select <PACKAGE-NAME>
      ```
      or build packages recursively
      ```
      colcon build --packages-up-to <PACKAGE-NAME>
      ```
      or if using python/launch/config files, this won't require subsequent rebuilds when you change your code.
      ```
      colcon build --symlink-install
      ```