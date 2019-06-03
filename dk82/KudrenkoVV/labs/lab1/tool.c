#include  "tool.h"

// вспомогательные функции
int modul(int base)
{
	return (base >= 0) ? base : (base * -1); 
}

int power(int base, int pow)
{
	int result = 1, i = 0, _pow;

	if( pow == 0 ) {
		return 1;
	}
	else{
		_pow = modul(pow);
	}
	
	for(i = 0; i < _pow; i++)
		{
			result *= base;
		}
		
	return ( pow > 0 ) ? result :
	 (1 / result);
}

int sum(int base, int finish)
{
	int result = 0, i = 0;
	
	for(i = 0; i <= finish; i++)
	{
		result += base;
	}
	return result;
	
}


//функция для вычисления формулы
double Q(int a, int b, int c) {
	int d = 0;
	
	double _module = modul(a * c - b);
	double _power = power(c, 3);
	double _sum = sum( pow(2, d), a );
	
	if( _power == 0 ) {
		printf ( "Error\n" );
		exit(1);
	}
	
	return ( _module / _power * _sum );
}


