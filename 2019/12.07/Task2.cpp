/*Напишите программу на основе разделяй и властвуй позволяющую эффективно проверять принадлежность пары значений массиву.
Например, пара (2,3) принадлежит массиву [1,2,3,5,7,11,13,17], а пара (3,4) - нет.
Можно считать, что количество запросов многократно превышает размер массива.  
В комментариях напишите, почему перебор - эффективное.
Решение эффективно, потому что мы делаем (log по основанию 2)*n обращений к массиву*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int BinarySearch(vector<int>& v , int size, int a)
{
	int left = 0;
	int right = size;
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;
		if (a < v[midd])
		{
			right = midd - 1;
		}
		else if (a > v[midd])
		{
			left = midd + 1;
		}
		else
		{
			return midd;
		}
		if (left > right)
		{
			return -1;
		}
	}
}


int main()
{
	int size, a, b;
	cin >> size >> a >> b;
	vector<int> v(size);
	for (int i = 0; i < size; i++)
	{
		cin >> v[i];
	}
	bool isInclude;
	sort(v.begin(), v.end());
	if (BinarySearch(v, size, a) != -1 && BinarySearch(v, size, b) != -1)
	{
		isInclude = true;
	}
	else
	{
		isInclude = false;
	}
	cout << isInclude;
	return 0;
}
