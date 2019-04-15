#include "tool.h"

int module(int inValue)
{

	if (inValue < 0) {
		inValue *= -1;
	}
	return inValue;
}

int stage(int inValue, int inStage)
{
	if (inStage == 0) {
		return 1;
	}

	int Value = 1;

	for (int i = 0; i < inStage; i++)
	{
		Value *= inValue;
	}
	return Value;
}

int sum(int inValue, int inStep) {

	for (int i = 0; i < inStep; i++)
	{
		inValue += inValue;
	}
	return inValue;


}
