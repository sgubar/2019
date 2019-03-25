#include <stdio.h>
#include <time.h>


void fillArray(int arr[],int length){
srand(time(NULL));
for(int i=0;i<length;i++){
    arr[i]=rand()%10000;
}
}




void printArray(int arr[],int length){
for(int i=0;i<length;i++){
    printf(" %d ",arr[i]);
}
}



void BubbleSort(int arr[],int length){

for(int i=0;i<length;i++){
    for(int j=length-1;j>i;j--){
        if(arr[j]<arr[j-1]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
        }

}
}
}



void ChoiceSort(int arr[], int length_array) {
for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++){
    int temp = arr[0];
    for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++){
        if (arr[repeat_counter] > arr[element_counter])
        {
        temp = arr[repeat_counter];
        arr[repeat_counter] = arr[element_counter];
        arr[element_counter] = temp;
            }
        }
    }
}


void InsertSort(int array[], int length)
{
int temp,
item;
for (int counter = 1; counter < length; counter++)
{
    temp = array[counter];
    item = counter-1;
    while(item >= 0 && array[item] > temp)
        {
        array[item + 1] = array[item];
        array[item] = temp;
        item--;
        }
}
}
