/*
  ==============================================================================

    ActionManager.cpp
    Created: 28 Oct 2016 8:05:29pm
    Author:  bkupe

  ==============================================================================
*/

#include "ActionManager.h"


juce_ImplementSingleton(ActionManager)

ActionManager::ActionManager() :
	BaseManager<Action>("Actions"),
	forceDisabled(false)
{
}

ActionManager::~ActionManager()
{
}

void ActionManager::setForceDisabled(bool value)
{
	if (forceDisabled == value) return;
	forceDisabled = value;
	for (auto &i : items) i->setForceDisabled(forceDisabled);
}

void ActionManager::addItemInternal(Action * item, var data)
{
	DBG("Add item internal action manager");
	item->forceDisabled = forceDisabled;
}
