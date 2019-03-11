#include "math+.h"

int Fact(int number){
	if(number<0 )
	printf("Wrong input");
	int res=1;
	int i;
	for(i=1;i<=number;i++){
        res=res*i;
                    }
return res;
}






float Pow(float number, int power){

    int i;
    for(i=1;i<power;i++){
        number=number*number;
                            }
return number;
}






int Sum(int limit){
int result=0;
    for(int i=1;i<=limit;i++){
        result+=Fact(i);
                            }
return result;
}
