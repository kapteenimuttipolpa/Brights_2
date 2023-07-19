cmake_minimum_required(VERSION 3.2)

project(dingo)

add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(src)

add_subdirectory(tests)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PUBLIC custom_int) # Lisää tiedost