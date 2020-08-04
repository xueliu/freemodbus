set(DEMO demo)

add_executable(${DEMO} "")

target_sources(
        ${DEMO}
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/WIN32/demo.cpp
        ${CMAKE_CURRENT_LIST_DIR}/WIN32/stdafx.cpp
)

target_include_directories(
        ${DEMO}
        PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/WIN32>
)

target_link_libraries(
        ${DEMO}
        freemodbus
)