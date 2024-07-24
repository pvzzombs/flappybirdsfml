cmake_minimum_required(VERSION 3.5.0)
project(FlappyBird)

set(SFML_DIR "../SFML-2.6.1/build")
find_package(SFML COMPONENTS graphics window system REQUIRED)
add_executable(FlappyBird main.cpp)
target_link_libraries(FlappyBird PRIVATE sfml-graphics sfml-window sfml-system)
target_include_directories(FlappyBird PRIVATE ../SFML-2.6.1/include)