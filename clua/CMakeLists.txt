cmake_minimum_required(VERSION 3.13)

project(oink
        VERSION 0.0.1
        DESCRIPTION "A lua C module example"
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXXSTANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED include/oink/oink.hpp src/oink.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include ${LUA_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LUA_LIB})

if (CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
elseif (CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
endif()