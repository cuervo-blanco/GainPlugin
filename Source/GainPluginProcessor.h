#ifndef GAINPLUGINPROCESSOR_H
#define GAINPLUGINPROCESSOR_H

#include "GainPlugin.h"

class GainPluginProcessor : public Gainplugin {
    public: 
        GainPluginProcessor();
        ~GainPluginProcessor() override;

    private: 
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GainPluginProcessor)
};

#endif
