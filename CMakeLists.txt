cmake_minimum_required(VERSION 3.15)
project(httproto VERSION 0.1.0)


set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/httproto)
include_directories(tests)

add_library(httproto
        src/httproto.c
        include/httproto/httproto.h)

target_link_libraries(httproto
        http_parser)

add_executable(httproto-test
        src/httproto.c
        include/httproto/httproto.h
        tests/protocols.h
        tests/main.c)

target_link_libraries(httproto-test
        http_parser)