cmake_minimum_required(VERSION 3.17)
project(hko)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/incl)
file(GLOB_RECURSE SRC src/*.cpp)


add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME}
        sfml-graphics sfml-audio sfml-system sfml-window)

#todo set output folder