#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

namespace audio_plugin {
class Knob : public juce::LookAndFeel_V4 {
public:
  Knob(juce::Image knobStrip, int numFrames)
      : knobImage(knobStrip), frameCount(numFrames) {}

  void drawRotarySlider(juce::Graphics& g,
                        int x,
                        int y,
                        int width,
                        int height,
                        float sliderPosProportional,
                        float rotaryStartAngle,
                        float rotaryEndAngle,
                        juce::Slider& slider) override {
    juce::ignoreUnused(rotaryStartAngle, rotaryEndAngle, slider);
    const int frameHeight = knobImage.getHeight() / frameCount;
    const int frameIndex = juce::jlimit(
        0, frameCount - 1,
        int(sliderPosProportional * static_cast<float>(frameCount - 1)));

    g.drawImage(knobImage, x, y, width, height,      // destination
                0, frameIndex * frameHeight,         // source Y offset
                knobImage.getWidth(), frameHeight);  // source width/height
  }

private:
  juce::Image knobImage;
  int frameCount;
};
}  // namespace audio_plugin
