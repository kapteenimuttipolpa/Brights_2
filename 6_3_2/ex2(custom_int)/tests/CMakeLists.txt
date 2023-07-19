add_executable(test test_custom_int.cpp)

target_link_libraries(test PUBLIC custom_int)

target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/external)