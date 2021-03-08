cmake_minimum_required(VERSION 3.12)
project(framework)

set(CMAKE_CXX_STANDARD 14)
file(GLOB_RECURSE SRC src/*.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/incl)
add_library(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio sfml-system sfml-window)
target_include_directories(${PROJECT_NAME} PUBLIC
                            ${CMAKE_CURRENT_SOURCE_DIR}/incl)