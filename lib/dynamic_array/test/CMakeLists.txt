cmake_minimum_required(VERSION 3.17)
project(example_project)
file(GLOB_RECURSE SOURCES "../src/*.cpp" "../inc/*.hpp")

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../inc)
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
if (Boost_FOUND)
    message("Boost Lib Found")
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
endif()


set(BoostT ON)
set(GTest  OFF)
set(Catch  OFF)

if(${BoostT})
    message("Boost Test Configuration Starts")
    include_directories(test)
    file(GLOB_RECURSE TEST_SOURCES "Boost/*.cpp" "Boost/*.hpp")
    add_executable(${PROJECT_NAME}_boost_test ${TEST_SOURCES})

elseif(${GTest})
    message("Google Test Configuration Starts")
    include_directories(test)
    include_directories(../../googletest/googletest/include)
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    add_executable(${PROJECT_NAME}_test "Google/*.cpp")
    target_link_libraries(${PROJECT_NAME}_google_test gtest_main)

elseif(${CatchT})
    message("Catch Test Configuration Starts")
    file(GLOB_RECURSE TEST_SOURCES "Catch/*.cpp" "Catch/*.hpp")
    add_executable(${PROJECT_NAME}_catch_test ${TEST_SOURCES})
endif()
