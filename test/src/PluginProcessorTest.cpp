#include <doctest/doctest.h>

#include "gain/PluginProcessor.h"
#include <juce_audio_basics/juce_audio_basics.h>

using namespace audio_plugin;

struct JUCEMessageManagerInitializer {
  JUCEMessageManagerInitializer() { juce::MessageManager::getInstance(); }
  ~JUCEMessageManagerInitializer() { juce::MessageManager::deleteInstance(); }
};

JUCEMessageManagerInitializer juceMessageManagerInitializer;

TEST_SUITE("AudioPluginAudioProcessor") {
  TEST_CASE("Gain parameter changes affect output signal") {
    AudioPluginAudioProcessor processor;
    processor.prepareToPlay(44100.0, 512);

    juce::AudioBuffer<float> buffer(processor.getTotalNumInputChannels(), 4);
    buffer.clear();
    buffer.setSample(0, 0, 1.0f);
    buffer.setSample(0, 1, 0.5f);
    buffer.setSample(0, 2, -0.5f);
    buffer.setSample(0, 3, -1.0f);

    juce::MidiBuffer midi;

    *processor.parameters.getRawParameterValue("gain") = -6.0f;

    processor.processBlock(buffer, midi);

    float expectedGain = std::pow(10.0f, -6.0f / 20.0f);
    CHECK(doctest::Approx(buffer.getSample(0, 0)).epsilon(1e-6) ==
          1.0f * expectedGain);
    CHECK(doctest::Approx(buffer.getSample(0, 1)).epsilon(1e-6) ==
          0.5f * expectedGain);
    CHECK(doctest::Approx(buffer.getSample(0, 2)).epsilon(1e-6) ==
          -0.5f * expectedGain);
    CHECK(doctest::Approx(buffer.getSample(0, 3)).epsilon(1e-6) ==
          -1.0f * expectedGain);
  }

  TEST_CASE("State saving and loading retains gain value") {
    AudioPluginAudioProcessor proc;

    auto* p = proc.parameters.getParameter("gain");

    const float normalised = p->convertTo0to1(3.0f);

    p->setValueNotifyingHost(normalised);

    juce::MemoryBlock state;
    proc.getStateInformation(state);

    AudioPluginAudioProcessor restored;
    restored.setStateInformation(state.getData(),
                                 static_cast<int>(state.getSize()));

    auto* pRestored = restored.parameters.getParameter("gain");
    REQUIRE(pRestored->convertFrom0to1(pRestored->getValue()) ==
            doctest::Approx(3.0f).epsilon(0.01f));
  }
}
