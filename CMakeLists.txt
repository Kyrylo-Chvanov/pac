cmake_minimum_required(VERSION 3.31)
project(pac)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS        OFF)

add_executable(${PROJECT_NAME} src/pac.cc src/engine/camera.cc)

add_custom_target(run
  COMMAND ${PROJECT_NAME}
  DEPENDS ${PROJECT_NAME}
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/../
)

# find_package(raylib)
add_subdirectory(lib/raylib)
target_link_libraries(${PROJECT_NAME} raylib)