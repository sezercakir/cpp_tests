cmake_minimum_required(VERSION 3.17)

project(example_project)
file(GLOB_RECURSE SOURCES "src/*.cpp" "inc/*.hpp")

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(inc)
add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_library(lib::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:includes>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
        ${CMAKE_CURRENT_SOURCE_DIR})

set(BOOST_ROOT C:\\boost_1_78_0)
FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    message(OK)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

ENDIF()


set(GTEST 1)
if(GTEST)
    include_directories(test)
    #include_directories(../../lib/googletest/googletest/include)
    #include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    add_executable(${PROJECT_NAME}_test test/Boost/boost_test.cpp)
    #target_link_libraries(${PROJECT_NAME}_test gtest_main)
endif()
