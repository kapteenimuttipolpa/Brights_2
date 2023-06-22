add_executable(test test_personal_finance.cpp)

target_link_libraries(test PUBLIC personal_finance utils)

target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/external) 

