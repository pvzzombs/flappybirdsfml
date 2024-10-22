cmake_minimum_required(VERSION 3.13)
project(FlappyBird)

if(WIN32 AND MINGW)
  set(SFML_DIR "../SFML-2.6.1/build")
endif()

find_package(SFML COMPONENTS network audio graphics window system REQUIRED)
add_executable(FlappyBird main.cpp bird.cpp collision.cpp DeathScene.cpp MainScene.cpp pipe.cpp pipesManager.cpp RetryScene.cpp)

if(WIN32 AND MINGW)
  target_link_libraries(FlappyBird PRIVATE sfml-graphics sfml-window sfml-system)
  target_include_directories(FlappyBird PRIVATE ../SFML-2.6.1/include)
  target_link_options(FlappyBird PRIVATE "-mwindows")
endif()

file(COPY "${CMAKE_SOURCE_DIR}/resources" DESTINATION "${CMAKE_BINARY_DIR}")