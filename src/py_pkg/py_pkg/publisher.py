import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class PublisherNode(Node):
    def __init__(self):
        super().__init__('publisher')
        self.publisher_ = self.create_publisher(String, 'topic', 10)
        self.msg_ = String()
        self.counter_ = 0
        self.timer_ = self.create_timer(1.0, self.timer_callback)
        self.get_logger().info("ROS2 class node first test")
    
    def timer_callback(self):
        self.msg_.data = "Hello, world! " + str(self.counter_)
        #self.get_logger().info("Publishing -> " + self.msg_.data)
        self.publisher_.publish(self.msg_)
        self.counter_ = self.counter_ + 1

def main(args=None):
    rclpy.init(args=args)
    node = PublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()