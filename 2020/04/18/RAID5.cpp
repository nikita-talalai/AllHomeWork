#include <iostream>
#include <ctime>
using namespace std;

int main() 
{
	srand(time(0));
	int quantityOfInt, k, n, XOR;
	cout << "Enter a quantity of buffers: ";
	cin >> k;
	cout << "Enter a size of buffers: ";
	cin >> n;
	quantityOfInt = n * 1024 / 4;
	int** arr;
	arr = new int* [k];
	for (int i = 0; i < k; i++)
	{
	arr[i] = new int[quantityOfInt];
	}
	for (int i = 0; i < k; i++) 
	{
		for (int j = 0; j < quantityOfInt; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
	
	for (int j = 0; j < quantityOfInt; j++)
	{
		XOR = arr[0][j];
		for (int i = 1; i < k - 1; i++)
		{
			XOR ^= arr[i][j];
		}
		arr[k - 1][j] = XOR;
	}

	int brokenBuffer = rand() % k;
	int* restored = new int[quantityOfInt];

	for (int j = 0; j < quantityOfInt; j++) {
		XOR = 0;
		for (int i = 0; i < k; i++) {
			if (i != brokenBuffer)
			{
				XOR ^= arr[i][j];
			}    
		}
		restored[j] = XOR;
	}
	cout << "Restored buffer: ";
	for (int i = 0; i < quantityOfInt; i++)
	{
		cout << restored[i] << " ";
	}

	cout << endl;

	cout << "Broken buffer: ";
	int i = brokenBuffer;
	for (int j = 0; j < quantityOfInt; j++)
	{
		cout << arr[i][j] << " ";
	}

	cout << endl;

	for (int j = 0; j < quantityOfInt; j++) {
		if (arr[brokenBuffer][j] != restored[j]) 
		{
			cout << "Some error";
			return -1;
		}
	}
	cout << "RESTORING COMPLETE SUCCESSEFULLY";
	return 0;
}
