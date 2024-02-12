#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"

using std::placeholders::_1;

class Sub : public rclcpp::Node
{
    public :

        Sub();

    private :

        void topic_callback(const tutorial_interfaces::msg::Num &msg) const;

        rclcpp::Subscription<tutorial_interfaces::msg::Num>::SharedPtr subscription_;
};