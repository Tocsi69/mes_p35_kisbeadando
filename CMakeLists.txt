cmake_minimum_required(VERSION 3.8)
project(my_turtle_controller)

# Használja a szükséges ROS2 csomagokat
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(turtlesim REQUIRED)

# Az új C++ fájl hozzáadása
add_executable(draw_line src/draw_line.cpp)
ament_target_dependencies(draw_line rclcpp geometry_msgs)


# A program telepítésének beállítása
install(TARGETS draw_line
  DESTINATION lib/${PROJECT_NAME})

ament_package()
