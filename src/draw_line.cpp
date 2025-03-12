#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

class LineDrawer : public rclcpp::Node {
public:
    LineDrawer() : Node("line_drawer") {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        draw_lines();
    }

private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;

    void move_turtle(double linear, double angular, double duration) {
        auto msg = geometry_msgs::msg::Twist();
        msg.linear.x = linear;
        msg.angular.z = angular;
        publisher_->publish(msg);
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(duration * 1000)));
    }

    void stop_turtle() {
        move_turtle(0.0, 0.0, 0.5); // Turtle megállítása egy rövid időre
    }

    void draw_lines() {
        RCLCPP_INFO(this->get_logger(), "Adidas Logo in da makin'...");

	stop_turtle(); // Stop, mert sokszor az első lépest nem csinálja meg, így ez lesz az első lépés, így nem baj ha kimarad.
        move_turtle(0.0, -1.0, 0.6);  // Ráfordulunk az ívre
        stop_turtle();
	move_turtle(3.0, 1.5, 2.5); //Első alsó ív
	stop_turtle();
	move_turtle(0.0, 2.2, 1.3); //Ív végén vízszintbe fordulunk
	stop_turtle();
	move_turtle(3.0, 0.0, 2.0); //Egyenes
	stop_turtle();
	move_turtle(1.0, -1.5, 1.0); // Kicsi ív
	stop_turtle();
	move_turtle(0.0, -1.6, 2.5); //Ív végén vízszintesbe fordulunk
	stop_turtle();
	move_turtle(4.0, 0.0, 2.5); // Egyenes
	stop_turtle();
	move_turtle(0.0, 1.0, 2.0); //Kanyar az ívre
	stop_turtle();
	move_turtle(1.5, 0.5, 1.5); // Felfele ív
	stop_turtle();
	move_turtle(0.0, 1.5, 2.0); //Csúcson lefele fordulunk
	stop_turtle();
	move_turtle(2.0, 1.2, 2.0); // Csúcs utáni ív
	stop_turtle();
	move_turtle(0.0, -2.5, 2.5); // Fordulunk a felső ívre
	stop_turtle();
	move_turtle(1.7, 0.7, 1.5); //Húzzuk az ívet
	stop_turtle();
	move_turtle(0.0, 1.5, 2.0); //Ráfordulunk az ívre
	stop_turtle();
	move_turtle(1.5, 0.7, 1.5); //Húzzuk az ívet
	stop_turtle();
	move_turtle(0.0, -2.5, 2.5); //Fordulunk
	stop_turtle();
	move_turtle(2.0, 1.2, 1.5);
	stop_turtle();
	move_turtle(0.0, 1.3, 2.0);
	stop_turtle();
	move_turtle(1.0, 0.5, 0.5);

        RCLCPP_INFO(this->get_logger(), "Örülünk mert ennyit nem szívtam semmivel még :D");
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LineDrawer>());
    rclcpp::shutdown();
    return 0;
}
