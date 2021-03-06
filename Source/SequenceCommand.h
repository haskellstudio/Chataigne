/*
  ==============================================================================

    SequenceCommand.h
    Created: 20 Feb 2017 2:12:09pm
    Author:  Ben

  ==============================================================================
*/

#ifndef SEQUENCECOMMAND_H_INCLUDED
#define SEQUENCECOMMAND_H_INCLUDED

#include "BaseCommand.h"
#include "SequenceModule.h"


class SequenceCommand :
	public BaseCommand,
	public EngineListener
{
public:
	SequenceCommand(SequenceModule * _module, CommandContext context, var params);
	virtual ~SequenceCommand();

	enum ActionType { PLAY_SEQUENCE, PAUSE_SEQUENCE, STOP_SEQUENCE, TOGGLE_SEQUENCE, ENABLE_LAYER, DISABLE_LAYER};

	ActionType actionType;
	SequenceModule * sequenceModule;

	BoolParameter * playFromStart;

	TargetParameter * target;

	virtual void trigger() override;


	var dataToLoad;

	virtual void loadJSONDataInternal(var data) override;
	virtual void endLoadFile() override;


	static BaseCommand * create(ControllableContainer * module, CommandContext context, var params);

	InspectableEditor * getEditor(bool isRoot) override;
};



#endif  // SEQUENCECOMMAND_H_INCLUDED
