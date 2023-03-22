cmake_minimum_required(VERSION 3.15)

project(shipbattle)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra")

add_executable(shipbattle gameplay.c  gameboard.c shipbattle.c)

add_library(rn SHARED rand_num.c)
target_link_libraries(shipbattle rn)

