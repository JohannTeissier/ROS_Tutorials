#include <functional>
#include <memory>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"

using namespace std::chrono_literals;

class Pub : public rclcpp::Node
{
    public :

        Pub();

    private :

        void timer_callback();

        rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        size_t count_;
};