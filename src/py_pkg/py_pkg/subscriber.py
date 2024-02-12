import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class SubscriberNode(Node):
    def __init__(self):
        super().__init__('subscriber')
        self.subscriber_ = self.create_subscription(String, 'topic', self.topic_callback, 10)
    
    def topic_callback(self, msg):
        self.get_logger().info("I heard the message : " + str(msg.data))

def main(args=None):
    rclpy.init(args=args)
    node = SubscriberNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()