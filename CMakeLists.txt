cmake_minimum_required(VERSION 3.1)
project(cppp.base)

function(info MSG)
    message(NOTICE ${MSG})
endfunction(info)

function(warn MSG)
    message(WARNING ${MSG})
endfunction(warn)
function(error MSG)
    message(SEND_ERROR ${MSG})
endfunction(error)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

set(LIBICONV_DIR ${CMAKE_SOURCE_DIR}/dependencies/cppp.libiconv)
#set(WORKING_DIRECTORY ${LIBICONV_DIR})
#set(CMAKE_CURRENT_SOURCE_DIR ${LIBICONV_DIR})

info("Building cppp.libiconv")
add_subdirectory(${LIBICONV_DIR})
#include(${LIBICONV_DIR}/CMakeLists.txt)
add_executable(myapp a.cpp)
set_target_properties(myapp PROPERTIES OUTPUT_NAME "myapp")

# 引入第三方库
#include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

target_link_libraries(myapp iconv.static)

