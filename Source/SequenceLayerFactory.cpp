/*
  ==============================================================================

    SequenceLayerFactory.cpp
    Created: 20 Nov 2016 3:09:30pm
    Author:  Ben Kuper

  ==============================================================================
*/

#include "SequenceLayerFactory.h"

#include "TriggerLayer.h"
#include "MappingLayer.h"
#include "AudioLayer.h"

juce_ImplementSingleton(SequenceLayerFactory)

SequenceLayerFactory::SequenceLayerFactory() {
	layerDefs.add(SequenceLayerDefinition::createDef("Trigger", &TriggerLayer::create));
	layerDefs.add(SequenceLayerDefinition::createDef("Audio", &AudioLayer::create));
	layerDefs.add(SequenceLayerDefinition::createDef("Automation", &MappingLayer::create)->addParam("mode",MappingLayer::MODE_1D));
	//layerDefs.add(SequenceLayerDefinition::createDef("Automation 2D", &MappingLayer::create)->addParam("mode", MappingLayer::MODE_2D));
	//layerDefs.add(SequenceLayerDefinition::createDef("Automation 3D", &MappingLayer::create)->addParam("mode", MappingLayer::MODE_3D));
	layerDefs.add(SequenceLayerDefinition::createDef("Color", &MappingLayer::create)->addParam("mode", MappingLayer::MODE_COLOR));

	buildPopupMenu();
}

void SequenceLayerFactory::buildPopupMenu()
{
	int id = 1;
	for (auto &d : layerDefs)
	{
		menu.addItem(id, d->type);
		id++;
	}

}

SequenceLayerDefinition * SequenceLayerDefinition::createDef(const String & _type, std::function<SequenceLayer*(Sequence*, var)> createFunc)
{
	SequenceLayerDefinition * s = new SequenceLayerDefinition(_type, createFunc);
	return s;
}

SequenceLayerDefinition * SequenceLayerDefinition::addParam(const String & paramName, var value)
{
	params.getDynamicObject()->setProperty(paramName, value);
	return this;
}
