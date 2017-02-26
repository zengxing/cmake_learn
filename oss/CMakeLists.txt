aux_source_directory(. oss_src)

FOREACH(src ${oss_src})
    get_filename_component(filename ${src} NAME)
    set_property(SOURCE ${src} APPEND PROPERTY COMPILE_DEFINITIONS __FILENAME__=\"${filename}\")  ##"
ENDFOREACH()


                   #OUTPUT oss_subsystem.o
add_custom_target(oss_subsystem
                  echo oss compile begin)
                   #COMMAND ${CMAKE_LINKER} -r -o oss_subsystem.o 
 
SET_SOURCE_FILES_PROPERTIES(
  oss_subsystem.o
  PROPERTIES
  EXTERNAL_OBJECT true
  GENERATED true
  )
set(zx  $<TARGET_OBJECTS:oss>)
message(STATUS "oss is  ${zx}")
add_library(oss STATIC ${oss_src} )
set_target_properties(oss PROPERTIES LINKER_LANGUAGE C )

add_dependencies(oss oss_subsystem)

add_custom_command(TARGET  oss POST_BUILD
                   COMMAND echo oss compile done)

add_custom_command(TARGET  oss PRE_BUILD
                   COMMAND echo oss compile begin)
#add_library(oss_subsystem STATIC  $<TARGET_OBJECTS:oss>)
#set_target_properties(oss_subsystem PROPERTIES LINKER_LANGUAGE C )
