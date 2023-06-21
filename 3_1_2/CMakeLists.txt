cmake_minimum_required(VERSION 3.2)

project(Weather)

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(${PROJECT_NAME} PUBLIC includes)

target_link_libraries(${PROJECT_NAME} PUBLIC weather utils user_inputs)