//Напишите функцию, которая удаляет из массива все простые числа встречающиеся больше одного раза.
#include <iostream>
using namespace std;


bool isPrime(int n) {
	if (n > 1) {
		for (int i = 2; i <= n / 2; i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}else{
		return false;
	}
}

void printarray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

void removeElement(int index, int arr[], int& n) {
	if (index == n - 1) {
		n--;
		return;
	}
	for (int i = index; i < n - 1; i++) {
		int temp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = temp;
	}
	n--;
}

void delete_duplicates(int& n, int arr[]) {
	bool dublicate = false;
	for (int i = n - 1; i >= 0; i--) {
		int value = arr[i];
		for (int j = i; j >= 0; j--) {
			if (isPrime(value) == true) {
				if (i != j) {
					if (value == arr[j]) {
						dublicate = true;
						removeElement(j, arr, n);
						i--;
					}
					if (j == 0) {
						if (dublicate == true) {
							removeElement(i, arr, n);
						}
					}
				}
			}
		}
		dublicate = false;
	}
}

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	delete_duplicates(n, arr);
	printarray(arr, n);

	return 0;
}
