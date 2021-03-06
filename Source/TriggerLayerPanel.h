/*
  ==============================================================================

    TriggerLayerPanel.h
    Created: 20 Nov 2016 3:07:50pm
    Author:  Ben Kuper

  ==============================================================================
*/

#ifndef TRIGGERLAYERPANEL_H_INCLUDED
#define TRIGGERLAYERPANEL_H_INCLUDED

#include "SequenceLayerPanel.h"
#include "TriggerLayer.h"

class TriggerLayerPanel :
	public SequenceLayerPanel
{
public:
	TriggerLayerPanel(TriggerLayer * layer);
	~TriggerLayerPanel();
	
	TriggerLayer * triggerLayer;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TriggerLayerPanel)
};



#endif  // TRIGGERLAYERPANEL_H_INCLUDED
