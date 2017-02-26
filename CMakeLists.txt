cmake_minimum_required (VERSION 2.8.4)
set(CMAKE_VERBOSE_MAKEFILE off)
project (hello)

set(SRC_LIST hello.c test.c)

add_subdirectory(oss)

FOREACH(src ${SRC_LIST})
    get_filename_component(filename ${src} NAME)
    set_property(SOURCE ${src} APPEND PROPERTY COMPILE_DEFINITIONS __FILENAME__=\"${filename}\" )###"
ENDFOREACH()

message(STATUS "ld is ${CMAKE_LINKER}")
add_library(main OBJECT ${SRC_LIST})
add_executable(hello $<TARGET_OBJECTS:main> )
target_link_libraries(hello -Wl,--whole-archive oss -Wl,-no-whole-archive )
#install(TARGETS hello DESTINATION d:) $<TARGET_OBJECTS:oss>rm