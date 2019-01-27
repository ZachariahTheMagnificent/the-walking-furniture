cmake_minimum_required(VERSION 3.11.0)
project(the-walking-furniture-executable VERSION 1.0.0)

add_executable(the-walking-furniture)
target_compile_features(the-walking-furniture PRIVATE cxx_std_17)
target_link_libraries(the-walking-furniture PRIVATE vulkan)
target_include_directories(the-walking-furniture PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_sources(the-walking-furniture PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp")
