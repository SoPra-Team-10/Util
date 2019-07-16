cmake_minimum_required(VERSION 3.10)

# Build options
set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror -march=native -mtune=native")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
    message("Building for debug")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    message("Building for release")
endif ()

# Building
project(SopraUtil VERSION 0.0.1 DESCRIPTION "Utilities for SoPra")

set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/Timer.cpp
    ${CMAKE_SOURCE_DIR}/src/Logging.cpp)

set(LIBS pthread)

include_directories(${CMAKE_SOURCE_DIR}/src)
add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBS})

# Installation via make install
include(GNUInstallDirs)
set_target_properties(${PROJECT_NAME} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
        PUBLIC_HEADER
        "src/Logging.hpp;src/Timer.h;src/AtDestruction.h")
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/SopraUtil)

add_subdirectory(Tests)
