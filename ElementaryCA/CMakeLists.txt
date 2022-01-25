cmake_minimum_required(VERSION 3.20)
project(CellAutomata)
set(CMAKE_VERBOSE_MAKEFILE ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
set(CMAKE_CXX_STANDARD 14)

include_directories(${CONAN_INCLUDE_DIRS_EIGEN})
add_executable(CellAutomata main.cpp ElementaryCA.cpp ElementaryCA.h)
target_link_libraries(CellAutomata ${CONAN_LIBS})