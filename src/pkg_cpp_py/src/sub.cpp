#include "../include/pkg_cpp_py/sub.hpp"

Sub::Sub() : Node("subscriber")
{
    this->subscription_ = this->create_subscription<interfaces::msg::Num>("topic", 10, std::bind(&Sub::callback_topic, this, _1));
    RCLCPP_INFO(this->get_logger(), "Start subscriber");
}

void Sub::callback_topic(const interfaces::msg::Num &msg) const
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
