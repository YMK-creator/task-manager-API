cmake_minimum_required(VERSION 3.30.7)
project(TaskManagerAPI)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_PATHS 
    ${PROJECT_SOURCE_DIR}/boost_1_88_0
    ${PROJECT_SOURCE_DIR}/Crow/Crow-1.2.1-Linux/include
)

add_executable(TaskManagerAPI src/main.cpp)

target_include_directories(TaskManagerAPI PUBLIC ${INCLUDE_PATHS})

target_compile_definitions(TaskManagerAPI PUBLIC CROW_USE_BOOST)

