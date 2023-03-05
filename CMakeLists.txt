cmake_minimum_required(VERSION 3.1)
project(cppp)

function(info MSG)
    message(NOTICE ${MSG})
endfunction(info)

function(warn MSG)
    message(WARNING ${MSG})
endfunction(warn)
function(error MSG)
    message(SEND_ERROR ${MSG})
endfunction(error)

set(LIBICONV_DIR "${CMAKE_SOURCE_DIR}/dependencies/libiconv-cmake")
set(WORKING_DIRECTORY ${LIBICONV_DIR})
set(CMAKE_CURRENT_SOURCE_DIR ${LIBICONV_DIR})
include(${LIBICONV_DIR}/CMakeLists.txt)

# 添加可执行文件
add_executable(myapp a.cpp)
# 引入第三方库
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)

target_link_libraries(myapp iconv)

