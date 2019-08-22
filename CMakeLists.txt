cmake_minimum_required(VERSION 3.0.0)
project(DesignPattern VERSION 0.1.0)


if (EXISTS "${CMAKE_SOURCE_DIR}/BuilderPattern/builderpattern_main.cpp")

add_executable(builderPattern_Ex01 ${CMAKE_SOURCE_DIR}/BuilderPattern/builderpattern_main.cpp)
endif()



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
