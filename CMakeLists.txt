cmake_minimum_required(VERSION 3.14)
project(task_manager)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(third_party/Crow/include)
include_directories(third_party/asio/asio-1.30.2/include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
  src/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
