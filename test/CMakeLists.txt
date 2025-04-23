cmake_minimum_required(VERSION 3.22)

project(PluginProcessorTest)

enable_testing()

add_executable(${PROJECT_NAME} src/PluginEditorTest.cpp src/PluginProcessorTest.cpp src/tests_main.cpp)

target_include_directories(
    ${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/../../plugin/include
                            ${JUCE_SOURCE_DIR}/modules
)

target_link_libraries(${PROJECT_NAME} PRIVATE AudioPlugin doctest::doctest)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()
