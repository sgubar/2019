#include "mathTools.h"


int hexToDec(char *number) {

	if (checkFormat(*number, *(number + 1)) == 0) {
		printf("Wrong format!\nPlease input properly: 0x7FFFFFFF (maximum)\n");
		return ERROR;
	}

	int result = 0; // Будущее число
	int counter = 0; //Общее значение знаков в выражении 0xFDE, counter = 5,  0x65, counter = 2
	char *numberPointer = number; //Воспомогательный указатель
	int maximumNumberQuantities = 8; //часть хекс числа после 0х, тоесть количесвто чисел в таком выражении -> 7FFFFFFF
	int numberQuantity = 0; //Дальше это будет номер чисел, тоесть counter - 2
	int position = 3; // Помогает вычислить степень в которую нужно будет возводить число 16

	while (*numberPointer != '\0') {
		numberPointer++;
		counter++;
	}


	if (counter - 2 > maximumNumberQuantities) {
		printf("Wrong format! Too many numbers\nPlease input properly: 0x7FFFFFFF (maximum 8 numbers)\n");
		return ERROR;
	}

	
    number += 2; // Беру только числа без кода 0х

	while (*number != '\0') {
		if ((*number >= '0' && *number <= '9') || (*number >= 'a' && *number <= 'f') || (*number >= 'A' && *number <= 'F')) {
			result += hexCharToInt(*number) * numToPositivePow(16,counter - position); // Чтобы перевести хекс в декБ нужно уможить число на 16 в степени порядкового номера числа, 7DE = (7 * 16^2) + (13 * 16^1) + (14 * 16^0) 
		}
		else {
			printf("Wrong input!\n You can only use number 0, ... , 9; letter upper or lower case a - f\n");
			return ERROR;
		}
		number++;
		position++;
	}

	return result;
}

int checkFormat(char first, char second) {
	if (first == '0' && (second == 'x' || second == 'X')) { // Если первые 2 буквы 0х тогда это хекс
		return 1;
	}
	else {
		return 0;
	}
}

int numToPositivePow(int num, int pow) { // возведение в степень
	if (pow < 0) {
		return ERROR;
	}

		int res = 1;
	
	for (int i = 0; i < pow; i++)
	{
		res *= num;
	}
	return res;
}

int hexCharToInt(char c) { //Перевожу чары в целочисленые числа
	if (c >= '0' && c <= '9') {
		return c - '0';
		}

	if (c >= 'a' && c <= 'f') {
		return 10 + (c - 'a');
	}

	if (c >= 'A' && c <= 'F') {
		return 10 + (c - 'A');
	}

	return ERROR;
}

int summIterate(int boundary) {
	if (boundary < 0) {
		return ERROR;
	}
	int a = 0;
	int res = 0;
	while (a != boundary) {
		a++;
		res += a;
	}
	return res;
}

int formuleCalculate(int c, int d, int f) {
	int summA = summIterate(d);
	int difference = f - c;

	if (summA == ERROR) {
		printf("No summs lower than 0!\n");
		return ERROR;
	}

	int result = summA * difference;
	return result;
}

void userFriendlyFunction() {
	int c = 0;
	int d = 0;
	char fString[256];
	int f = 0;
	int result;

	printf("Please input C as decimal number: \n");
	scanf_s("%i",&c);

	printf("Please input D as decimal number: \n");
	scanf_s("%i", &d);

	if(d < 0){
		printf("No summs lower than 0!\n");
		return ERROR;
	}

	printf("Please input F as hexadecimal number: \n");
	scanf_s("%s", fString, 255);


	f = hexToDec(fString);
	if (f == ERROR) {
		return ERROR;
	}

	result = formuleCalculate(c, d, f);

	printf("(Summ of 1 by %i) * (%i - %i) = %i      \n",d,f,c,result);
}