#include "../include/srv_client/server.hpp"


int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("AddThreeIntsServer");

    rclcpp::Service<tutorial_interfaces::srv::AddThreeInts>::SharedPtr service =
    node->create_service<tutorial_interfaces::srv::AddThreeInts>("AddThreeInts", &add);

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready");

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}

void add(const std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Request> request,
        std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Response> response)
{
    response->sum = request->a + request->b + request->c;
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sum = %ld", (long int)response->sum);
}