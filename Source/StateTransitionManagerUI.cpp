/*
  ==============================================================================

    StateTransitionManagerUI.cpp
    Created: 28 Jan 2017 11:01:29am
    Author:  Ben

  ==============================================================================
*/

#include "StateTransitionManagerUI.h"
#include "StateMachineView.h"

StateTransitionManagerUI::StateTransitionManagerUI(StateMachineView * sv, StateTransitionManager * stm) :
	BaseManagerUI("Transitions",stm,false),
	stateView(sv)
{
	transparentBG = true;
	animateItemOnAdd = false;
	setInterceptsMouseClicks(false, true);
	removeChildComponent(addItemBT);
	
	addExistingItems();
}


StateTransitionManagerUI::~StateTransitionManagerUI()
{

}

void StateTransitionManagerUI::resized()
{

}


StateTransitionUI * StateTransitionManagerUI::createUIForItem(StateTransition * s)
{
	StateViewUI * sourceUI = stateView->getUIForItem(s->sourceState);
	StateViewUI * destUI = stateView->getUIForItem(s->destState);
	return new StateTransitionUI(s, sourceUI, destUI);
}

void StateTransitionManagerUI::addItemUIInternal(StateTransitionUI * sui)
{
	sui->updateBounds();
}