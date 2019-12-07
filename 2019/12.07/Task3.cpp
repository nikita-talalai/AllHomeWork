/*Напишите программу для вычисления ЧФ с помощью разделяй и властвуй.*/

#include <iostream>
using namespace std;


int fib_n(int n)
{
	if (n <= 2) return 1;
	int x = 1;
	int y = 1;
	int ans = 0;
	for (int i = 2; i < n; i++)
	{
		ans = x + y;
		x = y;
		y = ans;
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	cout << fib_n(n);
	return 0;
}
