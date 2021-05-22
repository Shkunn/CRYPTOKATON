cmake_minimum_required(VERSION 3.10)

# set the project name
project(BeerCoin C CXX)

#add_executable(MyCrypto main.cc)
include_directories(src)
add_library(BeerCoin SHARED src)
set_target_properties(BeerCoin PROPERTIES LINKER_LANGUAGE CXX)


find_package(OpenSSL REQUIRED)
target_link_libraries(BeerCoin PRIVATE OpenSSL::Crypto)

