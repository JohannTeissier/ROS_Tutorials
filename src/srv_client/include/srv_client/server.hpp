#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/add_three_ints.hpp"

void add(const std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Request> request,
        std::shared_ptr<tutorial_interfaces::srv::AddThreeInts::Response> response);