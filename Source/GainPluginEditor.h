#ifndef GAINPLUGINEDITOR_H
#define GAINPLUGINEDITOR_H

#include "GainPluginProcessor.h"

class GainPluginEditor : public juce::AudioProcessorEditor {
    public : 
        GainPluginEditor(GainPluginProcessor& p);
        ~GainPluginEditor() override;

        void paint(juce::Graphic&) override;
        void resized() override;

    private: 
        GainPluginProcessor& processor;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GainPluginEditor)
};

#endif
