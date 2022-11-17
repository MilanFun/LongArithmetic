cmake_minimum_required(VERSION 2.8)

project(LongArithmetic)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/api/)
set(SOURCE_EXE main.cpp)
set(SOURCE_LIB ${CMAKE_CURRENT_SOURCE_DIR}/impl/Util.cpp ${CMAKE_CURRENT_SOURCE_DIR}/impl/BigIntegerImpl.cpp)
add_library(LongArithmetic STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})

target_link_libraries(main LongArithmetic)
