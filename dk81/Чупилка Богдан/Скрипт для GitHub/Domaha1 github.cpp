// Domaha1 github.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "stdio.h"

using namespace std;


  
int main() 

{
	setlocale(LC_ALL, "Russian");
	int maciv1[3][3];
	int maciv2[3][3];  // vod masiva //
	int num_m_col; // number, masiv, colonka ///
	int num_m_rad; // number, masiv, radok //
	int maciv_end[3][3];

	// for maciv1 //
	for (num_m_col = 0; num_m_col < 3; num_m_col++) {
		for (num_m_rad = 0; num_m_rad < 3; num_m_rad++) {
			printf("введить число [%i][%i] = ",num_m_col, num_m_rad);
			scanf_s("%i", &maciv1[num_m_col][num_m_rad]);
		}
	}

	// for maciv2 //
	for (num_m_col = 0; num_m_col < 3; num_m_col++) {
		for (num_m_rad = 0; num_m_rad < 3; num_m_rad++) {
			printf("введить число [%i][%i] = ", num_m_col, num_m_rad);
			scanf_s("%i", &maciv2[num_m_col][num_m_rad]);
		}
	}

	for (num_m_col = 0; num_m_col < 3; num_m_col++) 
	{
		printf("\n");
		for (num_m_rad = 0; num_m_rad < 3; num_m_rad++) 
		{
			maciv_end[num_m_col][num_m_rad] = maciv1[num_m_col][num_m_rad] - maciv2[num_m_col][num_m_rad];

			printf("%i ", maciv_end[num_m_col][num_m_rad]);

		}
	}
	 
	 
	
	return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
