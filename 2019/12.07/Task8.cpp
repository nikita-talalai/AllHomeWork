/*Напишите программу, находящую k-ую порядковую статистику. Программа должна работать за время O(n) в среднем.
Программа выводит k+1 порядковую статистику, так как в массивах индексация начинается с 0 */

#include <iostream>
#include <math.h>
using namespace std;


int partition(int*& arr, int l, int r)
{
	int middle = arr[(l + r) / 2];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (arr[i] < middle)
		{
			i++;
		}
		while (arr[j] > middle)
		{
			j--;
		}
		if (i >= j)
		{
			break;
		}
		swap(arr[i++], arr[j--]);
	}
	return j;
}

int findOrderStatistic(int*& arr, int k, int size) 
{
	int left = 0, right = size-1;
	while (true) 
	{
		int mid = partition(arr, left, right);

		if (mid == k) 
		{
			return arr[mid-1];
		}
		else if (k < mid) 
		{
			right = mid;
		}
		else 
		{
			left = mid + 1;
		}
	}
}



int main()
{
	int size, k;
	cin >> size >> k;
	int* arr = new int[size];
	for (int i = 0; i < size; i++) 
	{
		cin >> arr[i];
	}
	cout << findOrderStatistic(arr, k, size);
	return 0;
}
