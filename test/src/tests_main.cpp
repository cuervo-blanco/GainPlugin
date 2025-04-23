#define DOCTEST_CONFIG_IMPLEMENT
#include <doctest/doctest.h>
#include <juce_gui_basics/juce_gui_basics.h>

int main(int argc, char** argv) {
  juce::ScopedJuceInitialiser_GUI juceGui;

  doctest::Context ctx;
  ctx.applyCommandLine(argc, argv);
  int result = ctx.run();

  // juce::ImageCache::clear();
  juce::DeletedAtShutdown::deleteAll();

  return result;
}
