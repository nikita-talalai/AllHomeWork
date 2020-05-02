#include <iostream>
#include <random>
#include <time.h>
using namespace std;

long long int pow1(long long int a, long long int b) 
{
	long long int r = 1;
	for (int i = 0; i < b; i++) {
		r *= a;
	}
	return r;
}

long long int generationOfKeys(long long int phi, int e)
{
	long long int i = 1;
	while ((i * phi + 1) % e != 0) 
	{
		i++;
	}
	long long int d = (i * phi + 1) / e;
	return d;
}

long long int encryption(long long int a, long long int e, long long int n)
{
	long long int encryptedMessage = pow1(a, e) % n;
	return encryptedMessage;
}

long long int decryption(long long int encryptedMessage, long long int d, long long int n)
{
	long long int decryptedMessage = pow1(encryptedMessage, d) % n;
	return decryptedMessage;
}

int main() 
{
	srand(time(NULL));
	int p = rand() % 90000 + 10000;
	int q = rand() % 90000 + 10000;
	long long int n = p * q;
	long long int phi = (p - 1) * (q - 1);
	int e = 2389;
	long long int d = generationOfKeys(phi, e);
	int a;
	cout << "Enter an intenger: ";
	cin >> a;
	long long int encrypedMessage = encryption(a, e, n);
	cout << decryption(encrypedMessage, d, n) << endl;
	cout << a;


	return 0;
}
