project(HelloWorld)
cmake_minimum_required(VERSION 3.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_executable(hello_world main.c)

set(LIBXML2_TAG tags/v2.9.13)
include(ExternalLibXML2)

# find_package(LibXml2 REQUIRED)
target_include_directories(hello_world PUBLIC ${LIBXML2_INCLUDE_DIR} ${LIBXML2_INCLUDE_DIR_2})
target_link_libraries(hello_world PUBLIC libxml2)
install(TARGETS hello_world DESTINATION bin)