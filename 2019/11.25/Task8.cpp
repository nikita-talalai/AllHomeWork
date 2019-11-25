//Напишите функцию вычисляющую праймориал числа.Программа должна работать не более чем за O(n* log log n) шагов.
#include <iostream>
#include <math.h>
using namespace std;

long long int primorial(int n) {

	if (n == 0) {
		return 0;
	}
	int* arr = new int[n + 1]{ 0 };
	

	for (int i = 2; i <= sqrt(n) + 1; i++) {
		if (arr[i] == 0) {
			for (int j = i * i; j <= n + 1; j += i) {
				arr[j] = 1;
			}
		}
	}

	long long int primorial = 1;
	for (int i = 2; i < n + 1; i++) {
		if (arr[i] == 0) {
			primorial *= i;
		}
	}
	return primorial;
}


int main() {
	int n;
	cin >> n;
	cout << primorial(n);
	return 0;
}
