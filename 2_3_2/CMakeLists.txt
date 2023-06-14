cmake_minimum_required(VERSION 3.2)

project(Sensor)

add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC includes)

target_link_libraries(${PROJECT_NAME} PUBLIC datareads) # Lisää tiedostot

include(CTest)

set(MemoryCheckCommand "/usr/bin/valgrind")

add_test(NAME test_mem COMMAND ${PROJECT_NAME})



