#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"
#include <std_msgs/Float64.h>

//TODO: Include the ball_chaser "DriveToTarget" header file

// ROS::Publisher motor commands;
ros::Publisher motor_command_publisher;

// TODO: Create a handle_drive_request callback function that executes whenever a drive_bot service is requested
// This function should publish the requested linear x and angular velocities to the robot wheel joints
// After publishing the requested velocities, a message feedback should be returned with the requested wheel velocities

	//ros::Publisher linear_pub, angular_pub;

bool handle_drive_request(ball_chaser::DriveToTarget::Request& req,
ball_chaser::DriveToTarget::Response& res)
{
    ROS_INFO("DriveToTarget received - j1:%1.2f, j2:%1.2f", (float)req.linear_x, (float)req.angular_z);

	//Vector for values
	//std::vector<float> joints_values;
    	// Publish joint linear velocities and angular velocites to the vehicle
    	//std_msgs::Float64 joints_linear, joints_angular;
    	//joints_linear.data = joints_values[0];
    	//joints_angular.data = joints_values[1];
    	//linear_pub.publish(joints_linear);
    	//angular_pub.publish(joints_angular);

    // Wait 3 seconds for arm to settle
    ros::Duration(3).sleep();

// TODO:Make the necessary changes to publish the requested velocities instead of constant values

        // Create a motor_command object of type geometry_msgs::Twist
        geometry_msgs::Twist motor_command;
        // Set wheel velocities,
        motor_command.linear.x = req.linear_x;
        motor_command.angular.z = req.angular_z;
        // Publish angles to drive the robot
        motor_command_publisher.publish(motor_command);



    // Return a response message
    res.msg_feedback = "Wheel velocities set at linear: - j1: " + std::to_string((double)motor_command.linear.x) + " ,j2: " + std::to_string((double)motor_command.angular.z);

    ROS_INFO_STREAM(res.msg_feedback);

    return true;
}


int main(int argc, char** argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");

    // Create a ROS NodeHandle object
    ros::NodeHandle n;

    // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    // TODO: Define a drive /ball_chaser/command_robot service with a handle_drive_request callback function

	ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot",handle_drive_request);
ROS_INFO("Ready to send commands");

    
    

  

    // TODO: Handle ROS communication events
    ros::spin();

    return 0;
}
