cmake_minimum_required(VERSION 3.2)

project(cnt)

set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(tests)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)
include(CTest)

set(MemoryCheckCommand "/usr/bin/valgrind")

add_test(NAME test_mem COMMAND ${PROJECT_NAME})
#target_link_libraries(${PROJECT_NAME} PUBLIC container) # Lisää tiedostot
