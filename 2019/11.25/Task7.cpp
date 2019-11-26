//Напишите программу перебирающую все перестановки массива букв в лексикографическом порядке. 
//Программа должна работать не более чем за O(n!*n) шагов. 

#include <iostream>
using namespace std;

void sort(string& w, int len) 
{
	for (int startIndex = 0; startIndex < len - 1; ++startIndex)
	{
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < len; ++currentIndex)
		{
			if (w[currentIndex] < w[smallestIndex])	
				smallestIndex = currentIndex;
		}
		std::swap(w[startIndex], w[smallestIndex]);
	}
}

void NextPermutationAlgorithm(string &w,int len, string last)
{
	int factorial = 1;
	for (int i = 1; i <= len; i++) {
		factorial = factorial * i;
	}
	while (factorial != 0) {
		for (int i = len - 1; i > 0; i--) {
			if (w[i - 1] < w[i]) {
				int pivot = i;
				for (int j = pivot; j < len; j++) {
					if (w[j] <= w[pivot] && w[i - 1] < w[j]) {
						pivot = j;
					}
				}
				char temp = w[i - 1];
				w[i - 1] = w[pivot];
				w[pivot] = temp;
			
				for (int j = len - 1; i < j; j--) {
					temp = w[i];
					w[i] = w[j];
					w[j] = temp;
					i = i + 1;
				}
				break;
			}
		}
		cout << w << endl;
		factorial--;
		if (w == last) {
			return;
		}
	}
}

int main() {

	string w;

	cin >> w;

	int len = w.length();

	sort(w, len);

	string last = w;

	reverse(begin(last), end(last));

	cout << w << endl;

	NextPermutationAlgorithm(w, len, last);
	
	return 0;
}
