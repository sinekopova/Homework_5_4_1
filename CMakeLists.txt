cmake_minimum_required(VERSION 3.20)
project(homework_5_4_1)
add_executable(homework_5_4_1 homework_5_4_1.cpp classes.cpp)

add_subdirectory(../Catch2 Catch2-build)

add_executable(TestHomework_5_4_1 test-homework_5_4_1.cpp classes.cpp)
target_link_libraries(TestHomework_5_4_1 PRIVATE Catch2::Catch2)