/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic startup code for a Juce application.
 
 ==============================================================================
 */

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "StereoWidthCtrl2.h"
#include "juce_Reverb.h"

//==============================================================================
/**
 */
class StereoWidthCtrl2AudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    StereoWidthCtrl2AudioProcessor();
    ~StereoWidthCtrl2AudioProcessor();
    
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();
    
    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);
    
    //==============================================================================
    AudioProcessorEditor* createEditor();
    bool hasEditor() const;
    
    //==============================================================================
    const String getName() const;
    
    int getNumParameters();
    
    float getParameter (int index);
    void setParameter (int index, float newValue);
    
    const String getParameterName (int index);
    const String getParameterText (int index);
    
    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;
    
    bool acceptsMidi() const;
    bool producesMidi() const;
    bool silenceInProducesSilenceOut() const;
    double getTailLengthSeconds() const;
    
    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);
    
    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);
    
	//Custom Methods, Params and Public Data
	enum UserParameters{StereoBypass=0, StereoWidth, Roomsize, Damping, Wetlevel, Drylevel, Reverbwidth, Freezemode, threshold, ratio, ReverbBypass, CompressorBypass, totalNumParam};
	bool NeedsUIUpdate(){return UIUpdateFlag;};
	void RequestUIUpdate(){UIUpdateFlag=true;};
	void ClearUIUpdateFlag(){UIUpdateFlag=false;};
private:
	//Private Data, helper methods etc.
	float UserParams[totalNumParam];
	StereoWidthCtrl2 mWidthControl;
    Reverb areverb;
    Reverb::Parameters newparameter;
	bool UIUpdateFlag;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StereoWidthCtrl2AudioProcessor)
};

#endif  // PLUGINPROCESSOR_H_INCLUDED
