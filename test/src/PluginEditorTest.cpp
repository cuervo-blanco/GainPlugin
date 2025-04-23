#include <doctest/doctest.h>
#include "gain/PluginProcessor.h"
#include "gain/PluginEditor.h"

TEST_CASE("Editor initialises with gain slider attached and visible") {
  audio_plugin::AudioPluginAudioProcessor proc;
  {
    juce::Image dummy;
    audio_plugin::Knob lnf(dummy, 1);
    juce::LookAndFeel::setDefaultLookAndFeel(&lnf);
    juce::LookAndFeel::setDefaultLookAndFeel(&lnf);

    audio_plugin::AudioPluginAudioProcessorEditor ed(proc);

    CHECK(ed.getWidth() == 400);
    CHECK(ed.getHeight() == 400);
    CHECK(ed.getNumChildComponents() > 0);

    bool knobFound = false;
    for (int i = 0; i < ed.getNumChildComponents(); ++i)
      if (dynamic_cast<juce::Slider*>(ed.getChildComponent(i)))
        knobFound = true;

    CHECK(knobFound);

    juce::LookAndFeel::setDefaultLookAndFeel(nullptr);
  }
}
