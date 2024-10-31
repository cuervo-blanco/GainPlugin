cmake_minimum_required(VERSION 3.15)
project(GainPlugin VERSION 0.1.0)

include(FetchContent)

FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG 7.0.5 # Specify the desired JUCE version
)

set(JUCE_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(JUCE_BUILD_TOOLS OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(JUCE)

juce_add_plugin(GainPlugin
    COMPANY_NAME "tricerebrado"
    PRODUCT_NAME "GainPlugin"
    VERSION "0.1.0"
    DESCRIPTION "A straightforward simple gain plugin"
    FORMATS VST3 AU
)

set(SOURCES
    Source/GainPlugin.cpp
    Source/GainPluginProcessor.cpp
    Source/GainPluginEditor.cpp
)

set(HEADERS
    Source/GainPlugin.h
    Source/GainPluginProcessor.h
    Source/GainPluginEditor.h
)

target_sources(GainPlugin PRIVATE ${SOURCES} ${HEADERS})

target_link_libraries(GainPlugin PRIVATE
    juce::juce_audio_processors
    juce::juce_gui_extra
)

juce_generate_juce_header(GainPlugin)

