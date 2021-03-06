/*
  ==============================================================================

    ScriptFilter.cpp
    Created: 21 Feb 2017 6:59:12pm
    Author:  Ben

  ==============================================================================
*/

#include "ScriptFilter.h"

ScriptFilter::ScriptFilter()
{
	filterParams.addChildControllableContainer(&script);
}

ScriptFilter::~ScriptFilter()
{
}

void ScriptFilter::processInternal()
{
	Array<var> args;
	args.add(sourceParam->getScriptObject());
	if (script.scriptEngine == nullptr) return;
	var result = script.callFunction("filter", args);
	filteredParameter->setValue(result);
}

var ScriptFilter::getJSONData()
{
	var data = MappingFilter::getJSONData();
	data.getDynamicObject()->setProperty("script",script.getJSONData());
	return data;
}

void ScriptFilter::loadJSONDataInternal(var data)
{
	MappingFilter::loadJSONDataInternal(data);
	script.loadJSONData(data.getProperty("script", var()));
}
