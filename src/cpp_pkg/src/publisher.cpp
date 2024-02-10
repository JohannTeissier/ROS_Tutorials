#include "../include/cpp_pkg/publisher.hpp"

Publisher::Publisher() : Node("publisher"), count_(0)
{
    this->publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    this->timer_ = this->create_wall_timer(1s, std::bind(&Publisher::timer_callback, this));
    RCLCPP_INFO(this->get_logger(), "Start publisher");
}

void Publisher::timer_callback()
{
    auto message = std_msgs::msg::String();
    message.data = std::to_string(this->count_++);
    this->publisher_->publish(message);
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Publisher>());
    rclcpp::shutdown();

    return 0;
}
