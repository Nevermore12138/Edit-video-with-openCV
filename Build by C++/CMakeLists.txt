cmake_minimum_required(VERSION 3.13)
project(handleVedio)

set(OpenCV_DIR "D:/OpenCV3/opencv/build/x64/buildWithContib")
find_package(OpenCV REQUIRED)

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
message(STATUS "    lib path: ${LINK_LI}")

include_directories(${OpenCV_INCLUDE_DIRS})


set(CMAKE_CXX_STANDARD 14)

add_executable(handleVedio main.cpp vedioProcess.cpp)

target_link_libraries(handleVedio ${OpenCV_LIBS} )