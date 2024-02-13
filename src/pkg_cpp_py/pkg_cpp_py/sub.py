#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from interfaces.msg import Num

class Sub(Node) :
    def __init__(self) :
        super().__init__("subscriber")
        self.subscription_ = self.create_subscription(Num, "topic", self.callback_topic, 10)

    def callback_topic(self, msg) :
        self.get_logger().info("{}".format(msg.num))

def main(args=None) :
    rclpy.init(args=args)
    node = Sub()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__" :
    main()