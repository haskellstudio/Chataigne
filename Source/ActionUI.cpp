/*
  ==============================================================================

    ActionUI.cpp
    Created: 28 Oct 2016 8:05:24pm
    Author:  bkupe

  ==============================================================================
*/

#include "ActionUI.h"

ActionUI::ActionUI(Action * _action) :
	BaseItemUI<Action>(_action),
	action(_action)
{
	validUI = action->cdm.isValid->createToggle();
	validUI->showLabel = false;
	validUI->showValue = false;
	addAndMakeVisible(validUI);
}

ActionUI::~ActionUI()
{

}

void ActionUI::resizedInternalHeader(Rectangle<int>& r)
{
	validUI->setBounds(r.removeFromRight(headerHeight));
}
