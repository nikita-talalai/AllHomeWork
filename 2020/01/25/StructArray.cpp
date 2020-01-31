#include <iostream>
using namespace std;

struct Array
{
	int size;
	int* array;
	Array(int s, int* arr) 
	{
		size = s;
		array = new int[size];
		for (int i = 0; i < size; i++) 
		{
			array[i] = arr[i];
		}
		
		cout << "Здесь сработал конструктор" << endl;
	}
	~Array()
	{
		delete[] array;
		cout << "Здесь сработал деструктор" << endl;
	}
	Array(const Array& a) 
	{
		if (this != &a) 
		{
			size = a.size;
			array = new int[size];
			for (int i = 0; i < size; i++)
			{
				array[i] = a.array[i];
			}

		}
		cout << "Здеcь сработал конструктор копий" << endl;
	}
	const Array& operator=(const Array& a) 
	{
		if (this == &a) 
		{
			cout << "Здеcь сработал оператор равно. Один и тот же объект" << endl;
			return *this;
		}
		delete[] array;
		size = a.size;
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = a.array[i];
		}
		cout << "Здеcь сработал оператор равно" << endl;
		return *this;
	}
	const int& operator[](int i)
	{
		if ((i < 0) | (i >= size))
		{
			cout << "Error";
			return array[0];
		}
		return array[i];
	}
};

void print(Array& a)
{
	for (int i = 0; i < a.size; i++)
	{
		cout << a[i] << endl;
	}
}


int main() 
{
	setlocale(LC_ALL, "ru");
	int size;
	cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
	Array a(size, array);
	print(a);
	Array b(a);
	print(b);
	a = a;
	b = a;
	return 0;
}
