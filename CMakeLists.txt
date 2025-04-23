cmake_minimum_required(VERSION 3.22)

project(Gain)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)

include(cmake/cpm.cmake)

cpmaddpackage(
    NAME
    JUCE
    GIT_TAG
    8.0.6
    VERSION
    8.0.6
    GITHUB_REPOSITORY
    juce-framework/JUCE
    SOURCE_DIR
    ${LIB_DIR}/juce
)

cpmaddpackage(
    NAME
    DOCTEST
    GIT_TAG
    v2.4.11
    VERSION
    2.4.11
    GITHUB_REPOSITORY
    doctest/doctest
    SOURCE_DIR
    ${LIB_DIR}/doctest
)

include(cmake/CompilerWarnings.cmake)
include(cmake/Util.cmake)

add_subdirectory(plugin)

enable_testing()

add_subdirectory(test)
