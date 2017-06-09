cmake_minimum_required(VERSION 2.8)

project( MOT )

find_package( OpenCV REQUIRED )

add_executable( MOT main.cpp Vector2.cpp)

target_link_libraries( MOT ${OpenCV_LIBS})

