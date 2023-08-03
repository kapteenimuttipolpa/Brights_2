#add_compile_options(-fsanitize=address)

#add_link_options(-fsanitize=address)

add_executable(testi test_container.cpp)

target_include_directories(testi PUBLIC ${CMAKE_SOURCE_DIR}/external)
