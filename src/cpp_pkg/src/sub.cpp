#include "../include/cpp_pkg/sub.hpp"

Sub::Sub() : Node("subscriber")
{
    this->subscription_ = this->create_subscription<tutorial_interfaces::msg::Num>("topic", 10, std::bind(&Sub::topic_callback, this, _1));
    RCLCPP_INFO(this->get_logger(), "Start subscriber");
}

void Sub::topic_callback(const tutorial_interfaces::msg::Num &msg) const
{
    RCLCPP_INFO(this->get_logger(), "%ld", msg.num);
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Sub>());
    rclcpp::shutdown();

    return 0;
}
