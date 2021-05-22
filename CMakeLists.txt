project(CRYPTOKATON)

cmake_minimum_required(VERSION 3.16)

IF(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
ENDIF()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall  -O3 -march=native ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall   -O3 -march=native")

file(GLOB_RECURSE SOURCES src/*.cc)
file(GLOB_RECURSE HEADERS include/*.h)

link_libraries(-lcrypto)
ADD_EXECUTABLE(main ${HEADERS} ${SOURCES} main.cc)