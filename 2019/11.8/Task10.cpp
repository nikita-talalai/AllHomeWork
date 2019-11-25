/*Известно, что любое натуральное число можно представить в виде суммы не более чем четырех квадратов натуральных чисел.
Вася решил придумать аналогичное утверждение для кубов - он хочет узнать, сколько кубов достаточно для представления любого числа.
Его первая рабочая гипотеза - восемь. 
Выяснилось, что почти все числа, которые Вася смог придумать, представляются в виде суммы не более чем восьми кубов. 
Однако число 239, например, не допускает такого представления. 
Теперь Вася хочет найти какие-либо другие такие числа, а также, возможно, какую-либо закономерность в представлениях всех остальных чисел,
чтобы выдвинуть гипотезу относительно вида всех чисел, которые не представляются в виде суммы восьми кубов.
Помогите Васе написать программу, которая проверяла бы, возможно ли представить данное натуральное число в виде суммы не более чем восьми кубов натуральных чисел,
и если это возможно, то находила бы какое-либо такое представление.*/

#include <iostream>
using namespace std;

int cubeCount = 8;

int getCubesForNumber(int number, int limit) {
	int base = 0;
	int value = 0;
	int i = 1;

	while (true)
	{
		value = i * i * i;
		if (value <= number && (limit == 0 || i <= limit)) {
			base = i;
		}
		else {
			break;
		}
		i++;
	}

	return base;
}

bool calculateCubes(int number, int arr[], int& index, int limit) {

	if (number == 0) return true;

	index++;

	if (index > cubeCount - 1) return false;

	int base = getCubesForNumber(number, limit);
	int difference = number - base * base * base;

	arr[index] = base;

	if (difference == 0) return true;

	if (calculateCubes(difference, arr, index, base)) {
		if (index == cubeCount) return difference == 0;
		return true;
	}
	else {
		index--;
		base--;
		if (base > 0) {
			index--;
			return calculateCubes(number, arr, index, base);
		}
		else {
			return false;
		}
	}

}

int main() {
	int number;
	int count = -1;
	int* arr = new int[cubeCount];
	cin >> number;

	if (calculateCubes(number, arr, count, 0)) {
		for (int i = 0; i < cubeCount; i++)
		{
			if (i <= count)
				cout << arr[i] << " ";
		}

	}
	else {
		cout << "impossible";
	}

	

	return 0;
}
