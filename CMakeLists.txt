cmake_minimum_required(VERSION 3.5.0)
project(FlappyBird)

set(SFML_DIR "../SFML-2.6.1/build")
find_package(SFML COMPONENTS network audio graphics window system REQUIRED)
add_executable(FlappyBird main.cpp bird.cpp collision.cpp DeathScene.cpp MainScene.cpp pipe.cpp pipesManager.cpp RetryScene.cpp)
target_link_libraries(FlappyBird PRIVATE sfml-graphics sfml-window sfml-system)
target_include_directories(FlappyBird PRIVATE ../SFML-2.6.1/include)