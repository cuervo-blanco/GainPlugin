#ifndef GAINPLUGIN_H
#define GAINPLUGIN_H

#include <JuceHeader.h>

class GainPlugin : public juce::AudioProcessor {
    public:
        GainPlugin();
        ~GainPlugin() override;

        void prepareToPlay(double sampleRate, int samplesPerBlock) override;
        void releaseResources() override;
        void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
        
        juce::AudioProcessorEditor* createEditor() override;
        bool hasEditor() const override;

        const juce::String getName() const override;
        bool acceptsMidi() const override;
        bool producesMidi() const override;
        bool idMidiEffect() const override;
        double getTailLengthSeconds() const override;

        int getNumPrograms() override;
        int getCurrentProgram() override;
        void setCurrentProgram() override;
        const juce::String getProgramName(int index) override;
        void changeProgramName(int index, const juce::String& newName) override;

        void getStateInformation(juce::MemoryBlock& destData) override;
        void setStateInformation(const void* data, int sizeInBytes) override;

    private:
        float gain;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GainPlugin)
};

#endif