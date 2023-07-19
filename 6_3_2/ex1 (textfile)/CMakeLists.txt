cmake_minimum_required(VERSION 3.2)

project(fileread)

add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(src)

#add_subdirectory(tests)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME} PUBLIC c_file_read) # Lisää tiedost