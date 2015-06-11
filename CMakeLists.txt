cmake_minimum_required(VERSION 3.2)
project(CTE)

find_package(Boost 1.58 REQUIRED filesystem system)

include_directories(${Boost_INCLUDE_DIR})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/main.cpp)

add_executable(CTE ${SOURCE_FILES} src/process_template.h src/process_template.cpp)
target_link_libraries(CTE ${Boost_LIBRARIES})