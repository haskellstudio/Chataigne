/*
  ==============================================================================

    InverseFilter.h
    Created: 4 Feb 2017 5:39:15pm
    Author:  Ben

  ==============================================================================
*/

#ifndef INVERSEFILTER_H_INCLUDED
#define INVERSEFILTER_H_INCLUDED

#include "MappingFilter.h"

class InverseFilter :
	public MappingFilter
{
public:
	InverseFilter();
	~InverseFilter();

	void processInternal() override;
	
	static InverseFilter * create() { return new InverseFilter(); }
	virtual String getTypeString() const override { return "Inverse"; }

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(InverseFilter)
};



#endif  // INVERSEFILTER_H_INCLUDED
