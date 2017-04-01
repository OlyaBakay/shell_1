cmake_minimum_required(VERSION 3.6)
project(shell_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp cp.h)
add_executable(shell_1 ${SOURCE_FILES})
FIND_PACKAGE( Boost COMPONENTS filesystem program_options system REQUIRED )

INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

target_link_libraries( shell_1 ${Boost_LIBRARIES} )
