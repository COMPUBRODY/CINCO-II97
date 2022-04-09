#include "prefix.h"
////////////////////Activador de codecs ////////////////

ActCods::ActCods()
{}

int ActCods::SetOn(int term, int channel)
{
	cout<<"SetOn("<<term<<","<<channel<<")"<<endl;
	return 1;
}

int ActCods::SetOff(int channel)
{
	cout<<"SetOff("<<channel<<")"<<endl;
	return 1;
}