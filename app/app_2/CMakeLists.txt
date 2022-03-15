cmake_minimum_required(VERSION 3.17)

project(app2)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE SOURCES "src/*.cpp" )

add_executable(${PROJECT_NAME} ${SOURCES} )

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        #necessary libs
        lib)