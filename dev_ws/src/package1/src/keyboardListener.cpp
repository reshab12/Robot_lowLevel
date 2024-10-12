
#include "rclcpp/rclcpp.hpp"

class KeyboardListener : public rclcpp::Node{
    public:
        KeyboardListener():Node("keyboardListener"){
            subscriber_ = this->create_subscriber<>("topic", 10);

        }
};