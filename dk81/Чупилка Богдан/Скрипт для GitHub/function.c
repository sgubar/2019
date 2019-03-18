#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "function.h"

float Result=0;

float umnoz(float a, float b, float c){
	Result=a*c-b;
	return Result;
}

float module(float mnozResult){
	if(mnozResult<0){
		Result=mnozResult*(-1);
	}
	return Result;
}

float kub(float c){
	Result=c*c*c;
	return Result;
}

float division(float moduleResult, float kubResult){
	Result=moduleResult/kubResult;
	return Result;
}

float eks(float a) {
           if (a == 0) return 1;
            Result=pow(2,a) +eks(a-1);
            return Result;
                 }
        
float umnoz1(float divisionResult, float eksResult){
	Result=divisionResult*eksResult;
	return Result;
}

