cmake_minimum_required(VERSION 3.21.1)
project(GainPlugin VERSION 0.1.0)

set(JUCE_DIR "/home/soyhacker/Documents/JUCE/JUCE")
set(JUCE_BUILD_EXAMPLES OFF)
set(JUCE_BUILD_TOOLS OFF)

include(${JUCE_DIR}/CMake/JUCE.cmake)

juce_add_plugin(GainPlugin
    COMPANY_NAME "tricerebrado"
    PRODUCTNAME "GainPlugin"
    VERSION "0.1.0"
    DESCRIPTION "A straightforward simple gain plugin"
    FORMATS "VST3"
)

target_source(GainPlugin PRIVATE
    Source/GainPlugin.h
    Source/GainPlugin.h
    Source/GainPluginProcessor.h
    Source/GainPluginProcessor.cpp
    Source/GainPluginEditor.h
    Source/GainPluginEditor.cpp
)

target_link_libraries(GainPlugin PRIVATE juce::juce_audio_processors juce::juce_gui_extra)
