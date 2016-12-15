/*
  ==============================================================================

    AutomationKeyUI.cpp
    Created: 11 Dec 2016 1:22:27pm
    Author:  Ben

  ==============================================================================
*/

#include "AutomationKeyUI.h"

AutomationKeyUI::AutomationKeyUI(AutomationKey * key) :
	BaseItemMinimalUI(key)
{
	autoDrawHighlightWhenSelected = false;
	setRepaintsOnMouseActivity(true);
}

AutomationKeyUI::~AutomationKeyUI()
{
}


void AutomationKeyUI::paint(Graphics & g)
{

	int rad = AutomationKeyUI::handleSize;
	if (isMouseOver() || item->isSelected) rad += 3;
	Rectangle<float> er = getLocalBounds().withSizeKeepingCentre(rad,rad).toFloat();
	
	Colour c = item->isSelected ? HIGHLIGHT_COLOR : FRONT_COLOR;
	Colour cc = isMouseOver() ? YELLOW_COLOR : c.darker(.3f);
	g.setColour(c);
	g.fillEllipse(er);
	g.setColour(cc);
	g.drawEllipse(er,1);
}