# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(ReservationSystemProject VERSION 1.0 LANGUAGES CXX)

# Define the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(ReservationSystemApp
    main.cpp
    ReservationSystem.cpp
    Bus.cpp
)

# mkdir buildDefine include directories (if needed)
# include_directories(Bus Reservation)
target_include_directories(ReservationSystemApp PRIVATE ${CMAKE_SOURCE_DIR})
