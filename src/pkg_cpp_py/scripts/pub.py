#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from interfaces.msg import Num

class Pub(Node) :
    def __init__(self) :
        super().__init__("publisher")
        self.publisher_ = self.create_publisher(Num, "topic", 10)
        self.msg = Num()
        self.count_ = 0
        self.timer_ = self.create_timer(1.0, self.callback_timer)
        self.get_logger().info("Start publisher")

    def callback_timer(self) :
        self.msg.num = self.count_
        self.count_ += 1
        self.publisher_.publish(self.msg)

def main(args=None) :
    rclpy.init(args=args)
    node = Pub()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__" :
    main()