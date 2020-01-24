#include <iostream>
using namespace std;

struct Array
{
	int size;
	int* array;
	Array(int size,int* array) 
	{
		this->size = size;
		this->array = new int[size];
		this->array = array;
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
		if (this == &a)  return *this; 
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
		
};
void print(Array& a) 
{
	cout << a.array;
}
ostream& operator<<(ostream& out, const Array& a) {
	return out << a.array << endl << a.size;
};


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
	Array a(size,array);
	Array copy(a);
	cout << a << endl;
	cout << copy << endl;
	return 0;
}
