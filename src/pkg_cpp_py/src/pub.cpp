#include "../include/pkg_cpp_py/pub.hpp"

Pub::Pub() : Node("publisher"), count_(0)
{
    this->publisher_ = this->create_publisher<interfaces::msg::Num>("topic", 10);
    this->timer_ = this->create_wall_timer(1s, std::bind(&Pub::callback_timer, this));
    RCLCPP_INFO(this->get_logger(), "Start publisher");
}

void Pub::callback_timer()
{
    auto message = interfaces::msg::Num();
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
