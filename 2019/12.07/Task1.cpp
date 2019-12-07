/*Напишите функцию находящую корень монотонной вещественной функции f бинарным поиском(бисекцией).
Можно считать что корень обязательно существует. Корнем будем считать значение x, такое что |f(x)|<10^(-6).
В комментариях напишите, почему решение- эффективное. Функция y = k * x + b. Решение эффективное, так как используется бинарный поиск.*/
#include <iostream>
using namespace std;

double func(double y, double k, double b)
{
	double left = -1;
	double right = 1;
	double x = 0;
	while (right - left > 0.000001)
	{
		x = (right + left) / 2;
		if (x * k + b > y)
		{
			right = x;
		}
		else
			left = x;
	}
	return left;
}
int main()
{
	int y, k, b;
	cin >> y >> k >> b;
	cout << func(y, k, b);
	return 0;
}
