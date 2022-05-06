project(HelloWorld)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_executable(hello_world main.c)

set(LIBXML2_TAG tags/v2.9.13)
include(ExternalLibXML2)

target_include_directories(hello_world PUBLIC ${LIBXML2_INCLUDE_DIR} ${LIBXML2_INCLUDE_DIR_2})

if(WIN32)
  target_compile_definitions(hello_world PUBLIC -DLIBXML_STATIC)
  target_link_libraries(hello_world PUBLIC wsock32 ws2_32 libxml2)
else()
  target_link_libraries(hello_world PUBLIC libxml2)
endif()

install(TARGETS hello_world DESTINATION bin)

include(CheckLibraryExists)
CHECK_LIBRARY_EXISTS(m floor "" HAVE_M_LIB)

if(HAVE_M_LIB)
    target_link_libraries(hello_world PRIVATE m)
endif()
