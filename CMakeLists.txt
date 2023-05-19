cmake_minimum_required(VERSION 3.5)

project(expectedAvatar LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(expectedAvatar main.cpp)

install(TARGETS expectedAvatar
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
