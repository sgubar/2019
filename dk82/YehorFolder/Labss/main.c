#include <stdio.h>
#include <stdlib.h>
#include "math+.h"


int main(){
float RESULT;
float A,C,B;

printf("Please,enter  A parameter:");
scanf("%f",&A);

printf("Please,enter C parameter:");
scanf("%f",&C);

printf("Please,enter B parameter:");
scanf("%f",&B);

        if((int)B!=B){
            printf("You entered float B value,so impossible to handle Sum function");
            return -1;
        }



RESULT=(A*B)/(B+Pow(C,2))+Sum(B)+1;

        if((B+Pow(C,2))==0){
            printf("Dividing by 0 is impossible");
            return -1;
        }

printf("RESULT is %.2f",RESULT);




    return 0;
}
