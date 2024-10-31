#include "GainPlugin.h"

GainPlugin::GainPlugin() 
    : Audio Processor(
            BusesProperties()
            .withInput("Input", juce::AudioChannelSet::stereo(), true)
            .withOutput("Output", juce::AudioChannelSet::stereo(), true)
            ),
    gain(1.0f) {
    }

GainPlugin::~GainPlugin(){}

void GainPlugin::prepareToPlay(double sample_rate, int samples_per_block) {}

void GainPlugin::releaseResources() {}

void GainPlugin::processBlock(
        juce::AudioBuffer<float>& buffer, 
        juce::MidiBuffer& midiMessages
        ){
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; i++) {
        buffer.clear(i, 0, buffer.getNumSamples());
    }
    for (int channel = 0; channel < totalNumInputChannels; channel++) {
        auto* channelData = buffer.getWritePointer(channel);
        for (int sample = 0; sample < buffer.getNumSamples(); sample++){
            channelData[sample] *= gain;
        }
    }   
}

juce::AudioProcessEditor* GainPlugin::createEditor() { return nullptr; }

bool GainPlugin::hasEditor() const { 
    return false; 
}

const juce::String GainPlugin::getName() const {
    return JucePlugin_name; 
}

bool GainPlugin::acceptsMidi() const { 
    return false; 
}

bool GainPlugin::producesMidi() const { 
    return  false; 
}

bool GainPugin::isMidiEffect() const { 
    return false; 
} 

double GainPlugin::getTailLengthSeconds() const { 
    return 0.0; 
}

int GainPlugin::getNumPrograms() { 
    return 1; 
}

int GainPlugin::getCurrentProgram() { 
    return 0; 
}

void GainPlugin::setCurrentProgram(int index) {
}

const juce::String GainPlugin::getProgramName(int index) { 
    return {}; 
}

void GainPlugin::changeProgramName(int index, const juce::String& newName) {
}

void GainPlugin::getStateInformation(juce::MemoryBlock& destData) {
}

void GainPlugin::setStateInformation(const void* data, int sizeInBytes) {
}
