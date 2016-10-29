/*
  ==============================================================================

    TimeMachineView.cpp
    Created: 28 Oct 2016 8:26:25pm
    Author:  bkupe

  ==============================================================================
*/

#include "TimeMachineView.h"

TimeMachineView::TimeMachineView(SequenceManager * _manager) :
	ShapeShifterContent("Time Machine"),
	manager(_manager)
  {
  }

TimeMachineView::~TimeMachineView()
{
}

void TimeMachineView::paint(Graphics & g)
{
	g.fillAll(BG_COLOR.darker(.3f));
}