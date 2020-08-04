set(LIB freemodbus)

add_library(${LIB} "")

target_compile_definitions(
        ${LIB}
        PRIVATE
        "COMPONENT=\"${LIB}\""
)

target_compile_options(${LIB}
        PRIVATE
        -O3
        )

# install files while keeping folder structure
macro(INSTALL_WITH_HIERARCHY FILE_LIST DEST)
    foreach(F ${FILE_LIST})
        get_filename_component(F_DIR ${F} DIRECTORY)
        string(REPLACE ${CMAKE_CURRENT_LIST_DIR} "" DIR_REL ${F_DIR})
        install(FILES ${F} DESTINATION ${DEST}${DIR_REL}/)
    endforeach(F)
endmacro(INSTALL_WITH_HIERARCHY)

target_sources(
        ${LIB}
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/mb.c
        ${CMAKE_CURRENT_LIST_DIR}/ascii/mbascii.c
        ${CMAKE_CURRENT_LIST_DIR}/functions/mbfunccoils.c
        ${CMAKE_CURRENT_LIST_DIR}/functions/mbfuncdiag.c
        ${CMAKE_CURRENT_LIST_DIR}/functions/mbfuncdisc.c
        ${CMAKE_CURRENT_LIST_DIR}/functions/mbfuncholding.c
        ${CMAKE_CURRENT_LIST_DIR}/functions/mbfuncinput.c
        ${CMAKE_CURRENT_LIST_DIR}/functions/mbfuncother.c
        ${CMAKE_CURRENT_LIST_DIR}/functions/mbutils.c
        ${CMAKE_CURRENT_LIST_DIR}/rtu/mbcrc.c
        ${CMAKE_CURRENT_LIST_DIR}/rtu/mbrtu.c
        ${CMAKE_CURRENT_LIST_DIR}/../demo/WIN32/port/portevent.c
        ${CMAKE_CURRENT_LIST_DIR}/../demo/WIN32/port/portother.c
        ${CMAKE_CURRENT_LIST_DIR}/../demo/WIN32/port/portserial.c
        ${CMAKE_CURRENT_LIST_DIR}/../demo/WIN32/port/porttimer.c
)

target_include_directories(
        ${LIB}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/ascii>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/rtu>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/tcp>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/demo/WIN32/port>
        $<INSTALL_INTERFACE:include>
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_BINARY_DIR})