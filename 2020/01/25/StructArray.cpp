#include <iostream>
using namespace std;

struct Vector
{
	int size;
	int capacity;
	int* array;
	Vector(int s, int* arr)
	{
		size = s;
		capacity = size;
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = arr[i];
		}

		cout << "Здесь сработал конструктор" << endl;
	}
	~Vector()
	{
		delete[] array;
		cout << "Здесь сработал деструктор" << endl;
	}
	Vector(const Vector& a)
	{
		if (this != &a)
		{
			size = a.size;
			capacity = a.capacity;
			array = new int[size];
			for (int i = 0; i < size; i++)
			{
				array[i] = a.array[i];
			}

		}
		cout << "Здеcь сработал конструктор копий" << endl;
	}
	const Vector& operator=(const Vector& a)
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
	void push_back(int x)
	{
		if (size == capacity)
		{
			capacity *= 2;
			int* temp = new int[capacity];
			for (int i = 0; i < size; i++)
			{
				temp[i] = array[i];
			}
			delete[] array;
			array = temp;
		}
		array[size] = x;
		size++;
		cout << "Добавили в конец число" << endl;
	}
	void resize(int x)
	{
		if (x > capacity)
		{
			capacity += x - capacity;
		}
		size = x;
		cout << "Изменили размер" << endl;
	}
	};

	void print(Vector& a)
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
	Vector a(size, array);
	print(a);
	Vector b(a);
	print(b);
	a = a;
	b = a;
	a.push_back(2);
	print(a);
	a.resize(3);
	print(a);
	cout << "Текущий размер: " << a.size << endl;
	return 0;
}
