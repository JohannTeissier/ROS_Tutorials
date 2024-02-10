import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class Publisher(Node) :
    def __init__(self) :
        super().__init__("publisher")
        self.publisher_ = self.create_publisher(String, "topic", 10)
        self.msg_ = String()
        self.counter_ = 0
        self.timer_ = self.create_timer(1.0, self.timer_callback)
        self.get_logger().info("Start publisher")

    def timer_callback(self) :
        self.msg_.data = str(self.counter_)
        self.publisher_.publish(self.msg_)
        self.counter_ += 1

def main(args = None) :
    rclpy.init(args = args)
    node = Publisher()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__" :
    main()