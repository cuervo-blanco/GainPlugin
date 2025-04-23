#include "gain/PluginEditor.h"
#include "gain/PluginProcessor.h"
#include "gain/Knob.h"
#include "BinaryData.h"

namespace audio_plugin {
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(
    AudioPluginAudioProcessor& p)
    : AudioProcessorEditor(&p),
      processorRef(p),
      customKnob(
          juce::ImageCache::getFromMemory(BinaryData::knob_strip_png,
                                          BinaryData::knob_strip_pngSize),
          64) {
  juce::ignoreUnused(processorRef);
  setSize(400, 400);

  gainSlider.setSliderStyle(juce::Slider::Rotary);
  gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
  gainSlider.setLookAndFeel(&customKnob);

  gainSlider.setRange(-96.0, 24.0, 0.1);
  gainSlider.setValue(0.0);

  addAndMakeVisible(gainSlider);

  gainAttachment =
      std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
          p.parameters, "gain", gainSlider);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() {
  gainSlider.setLookAndFeel(nullptr);
}

void AudioPluginAudioProcessorEditor::paint(juce::Graphics& g) {
  juce::Image bg = juce::ImageCache::getFromMemory(
      BinaryData::background_png, BinaryData::background_pngSize);

  g.fillAll(
      getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

  gainSlider.setName("Gain");
  gainSlider.setTextValueSuffix(" dB");
  g.drawImage(bg, getLocalBounds().toFloat());

  // g.setColour(juce::Colours::red);
  // g.drawRect(gainSlider.getBounds());
}

void AudioPluginAudioProcessorEditor::resized() {
  gainSlider.setBounds(getLocalBounds().reduced(100));
}

}  // namespace audio_plugin
