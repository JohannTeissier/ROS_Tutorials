from launch import LaunchDescription
from launch_ros.actions import Node
import os

def generate_launch_description():
	ld=LaunchDescription()

	N1_node = Node(
    	package="pkg_cpp_py",
    	executable="talker_cpp",
		name="talker_cpp"
	)
	N2_node=Node(
    	package="pkg_cpp_py",
    	executable="listener_cpp",
		name="listener_cpp"
	)

	ld.add_action(N1_node)
	ld.add_action(N2_node)
    
	return ld
