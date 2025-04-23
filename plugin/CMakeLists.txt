cmake_minimum_required(VERSION 3.22)

project(AudioPlugin VERSION 0.1.0)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/gain")
set(RESOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/resources")

juce_add_plugin(
    ${PROJECT_NAME}
    COMPANY_NAME
    "CuervoBlanco"
    IS_SYNTH
    FALSE
    NEEDS_MIDI_INPUT
    FALSE
    NEEDS_MIDI_OUTPUT
    FALSE
    PLUGIN_MANUFACTURER_CODE
    Cubl
    PLUGIN_CODE
    Gain
    FORMATS
    VST3
    AU
    AAX
    Standalone
    PRODUCT_NAME
    "Gain"
)

juce_add_binary_data(
    GainAssets
    SOURCES
    ${RESOURCES_DIR}/ui/background.png
    ${RESOURCES_DIR}/ui/knob_strip.png
    ${RESOURCES_DIR}/icons/icon.png
)
set(SOURCE_FILES src/PluginEditor.cpp src/PluginProcessor.cpp)

set(HEADER_FILES ${INCLUDE_DIR}/PluginEditor.h ${INCLUDE_DIR}/PluginProcessor.h ${INCLUDE_DIR}/Knob.h)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries_system(${PROJECT_NAME} PUBLIC juce::juce_audio_utils)
target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC juce::juce_recommended_config_flags
           juce::juce_recommended_lto_flags
           juce::juce_recommended_warning_flags
           GainAssets
)

target_compile_definitions(${PROJECT_NAME} PUBLIC JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 JUCE_VST3_CAN_REPLACE_VST2=0)

set_source_files_properties(${SOURCE_FILES} PROPERTIES COMPILE_OPTIONS "${PROJECT_WARNINGS_CXX}")

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/..)
