/*
  ==============================================================================

    MIDICommands.h
    Created: 20 Dec 2016 3:45:21pm
    Author:  Ben

  ==============================================================================
*/

#ifndef MIDICOMMANDS_H_INCLUDED
#define MIDICOMMANDS_H_INCLUDED

#include "BaseCommand.h"

class MIDIModule;

class MIDICommand :
	public BaseCommand
{
public:
	MIDICommand(MIDIModule * module, CommandContext context, var params);
	virtual ~MIDICommand();

	MIDIModule *  midiModule;

	static BaseCommand * create(ControllableContainer * module, CommandContext context, var params) { return new MIDICommand((MIDIModule *)module, context, params); }

};

class MIDINoteAndCCCommand :
	public MIDICommand
{
public:
	MIDINoteAndCCCommand(MIDIModule * module, CommandContext context, var params);
	~MIDINoteAndCCCommand();

	enum MessageType {NOTE_ON,NOTE_OFF,CONTROLCHANGE};
	
	MessageType type;

	IntParameter * channel;
	EnumParameter * noteEnum;
	IntParameter * octave;
	IntParameter * number; //for CC
	IntParameter * velocity;

	void setValue(var value) override;
	void trigger() override;

	static BaseCommand * create(ControllableContainer * module, CommandContext context, var params) { return new MIDINoteAndCCCommand((MIDIModule *)module, context, params); }

};



#endif  // MIDICOMMANDS_H_INCLUDED
