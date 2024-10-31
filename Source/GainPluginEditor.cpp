#include "GainPluginEditor.h"

GainPluginEditor::GainPluginEditor(GainPluginProcessor& p)
    : AudioProcessorEditor(&p), processor(p) {
        setSize(400, 300);
    }

GainPluginEditor::~GainPluginEditor() {
}

void GainPluginEditor::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
}

void GainPluginEditor::resized() {
}
