# Project-2-Go-Chase-It
Build a bold chaser mobile robot with ros, First: Design Robot, Second: Program it to chase a ball
drive_bot:

Create a my_robot ROS package to hold your robot, the white ball, and the world.
Design a differential drive robot with the Unified Robot Description Format. Add two sensors to your robot: a lidar and a camera. Add Gazebo plugins for your robot’s differential drive, lidar, and camera. The robot you design should be significantly different from the one presented in the project lesson. Minimum required changes are adjusting the color, wheel radius, and chassis dimensions. You can also completely redesign the robot model!

ball_chaser:

Create a ball_chaser ROS package to hold your C++ nodes.
Write a drive_botC++ node that will provide a ball_chaser/command_robot service to drive the robot by controlling its linear x and angular z velocities. The service should publish to the wheel joints and return back the requested velocities.
Write a process_image C++ node that reads your robot’s camera image, analyzes it to determine the presence and position of a white ball. If a white ball exists in the image, your node should request a service via a client to drive the robot towards it.
The ball_chaser.launch should run both the drive_bot and the process_image nodes.
<img width="923" alt="Setup" src="https://user-images.githubusercontent.com/26072511/176583755-f81df7cd-9665-4d2f-b18a-012fe0981acd.png">

Image Message
![image](https://user-images.githubusercontent.com/26072511/185021542-2a3bd254-f5e9-4e2c-aad8-f8cbaac4d521.png)
