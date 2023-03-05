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
#"${CMAKE_SOURCE_DIR}/dependence/libiconv-cmake"




set(LIBICONV_DIR "${CMAKE_SOURCE_DIR}/dependencies/libiconv-cmake")
set(WORKING_DIRECTORY ${LIBICONV_DIR})
set(CMAKE_CURRENT_SOURCE_DIR ${LIBICONV_DIR})
#set(CMAKE_CURRENT_SOURCE_DIR ${PROJECT_SOURCE_DIR})
include(${LIBICONV_DIR}/CMakeLists.txt)

