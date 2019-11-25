//Напишите программу заполняющую квадратный двумерный массив, как показано в примере.
//На главной диагонали стоят нули, а на остальных - удаление от главной диагонали.
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



void dig_trench(int n, int** arr) {
	for (int l = 0; l < n; l++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i + l == j) {
					arr[i][j] = l;

				}
				if (i == j + l) {
					arr[i][j] = l;
					
				}
			}
		}
	}

}


int main() {
	int n;
	cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	dig_trench(n, arr);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
