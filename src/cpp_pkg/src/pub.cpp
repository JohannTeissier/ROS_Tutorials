#include "../include/cpp_pkg/pub.hpp"

Pub::Pub() : Node("publisher"), count_(0)
{
    this->publisher_ = this->create_publisher<tutorial_interfaces::msg::Num>("topic", 10);
    this->timer_ = this->create_wall_timer(1s, std::bind(&Pub::timer_callback, this));
}

void Pub::timer_callback()
{
    auto message = tutorial_interfaces::msg::Num();
    message.num = this->count_++;
    this->publisher_->publish(message);
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Pub>());
    rclcpp::shutdown();

    return 0;
}
