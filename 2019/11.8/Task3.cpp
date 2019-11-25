//Напишите функцию, заполняющую квадратный двумерный массив пирамидой, как показано в примере.
#include <iostream>
using namespace std;
int min(int a, int b)
{
	if (a > b) {
		return b;
	}
	else {
		return a;
	}
}

void build_ziggurat(int n,int **arr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = min(min(n - j, j + 1), min(n - i, i + 1));
		}
	}
}

int main() {
	int n;
	cin >> n;
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	build_ziggurat(n, arr);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}

	return 0;
}
