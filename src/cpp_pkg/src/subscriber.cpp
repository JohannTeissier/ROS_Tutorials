#include "../include/cpp_pkg/subscriber.hpp"

Subscriber::Subscriber() : Node("subscriber")
{
    this->subscription_ = this->create_subscription<std_msgs::msg::String>("topic", 10, std::bind(&Subscriber::topic_callback, this, _1));
}

void Subscriber::topic_callback(const std_msgs::msg::String &msg) const
{
    RCLCPP_INFO(this->get_logger(), "%s", msg.data.c_str());
}

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Subscriber>());
    rclcpp::shutdown();

    return 0;
}
