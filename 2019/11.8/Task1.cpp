//Напишите функцию, которая удаляет из массива все элементы, которые уже встречались.
#include <iostream>
using namespace std;

void printarray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

void removeElement(int index, int arr[], int& count) {
	if (index == count - 1) return;
	for (int i = index; i < count - 1; i++) {
		arr[i] = arr[i + 1];
	}
}

void delete_duplicates(int& n, int arr[]) {
	for (int i = n - 1; i >= 0; i--) {
		int value = arr[i];
		for (int j = i + 1; j < n; j++) {
			if (value == arr[j]) {
				removeElement(j, arr, n);
				n--;
			}
		}
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
