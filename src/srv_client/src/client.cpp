#include "../include/srv_client/client.hpp"

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);

    if(argc != 4)
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: add_three_ints_client X Y Z");
        return 1;
    }

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("AddThreeIntsClient");
    rclcpp::Client<tutorial_interfaces::srv::AddThreeInts>::SharedPtr client =
    node->create_client<tutorial_interfaces::srv::AddThreeInts>("AddThreeInts");

    auto request = std::make_shared<tutorial_interfaces::srv::AddThreeInts::Request>();
    request->a = atoll(argv[1]);
    request->b = atoll(argv[2]);
    request->c = atoll(argv[3]);

    while(!client->wait_for_service(1s))
    {
        if(!rclcpp::ok())
        {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            return 0;
        }

        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
    }

    auto result = client->async_send_request(request);

    if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS)
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Sum: %ld", result.get()->sum);
    else
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service AddThreeInts");

  rclcpp::shutdown();
  return 0;
}