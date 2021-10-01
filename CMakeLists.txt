cmake_minimum_required(VERSION 3.20)
project(DataBase)

add_library(${PROJECT_NAME}.Library INTERFACE)
target_include_directories(${PROJECT_NAME}.Library INTERFACE ${PROJECT_NAME})

add_executable(${PROJECT_NAME}.test main.cpp)
target_link_libraries(${PROJECT_NAME}.test PRIVATE ${PROJECT_NAME}.Library)

set_target_properties(${PROJECT_NAME}.test PROPERTIES CXX_STANDARD 20)