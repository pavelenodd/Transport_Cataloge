cmake_minimum_required(VERSION 3.0.0)

project(Transport_Catalog VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Transport_Catalog main.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS${CMAKE_CXX_FLAGS}"-Wall -Werror") 
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#