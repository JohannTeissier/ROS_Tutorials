#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "interfaces/msg/num.hpp"

using std::placeholders::_1;

class Sub : public rclcpp::Node
{
    public :

        Sub();

    private :

        void callback_topic(const interfaces::msg::Num &msg) const;

        rclcpp::Subscription<interfaces::msg::Num>::SharedPtr subscription_;
};