#include "GainPluginProcessor.h"

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new GainPluginProcessor();
}
GainPluginProcessor::GainPluginProcessor() : GainPlugin() {}
GainPluginProcessor::~GainPluginProcessor() {}

