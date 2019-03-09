#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int arr[10000001] = { 0 };
void eratosthenes(int size) {
	for (int i = 2; i*i < size; i++)
		if (!arr[i])
			for (int j = i * i; j < size; j += i)
				arr[j] = 1;
	arr[1] = 1;
}

void printprime(int input, int size)
{
	int i = 2;
	while (input != 1)
	{
		if (i > size)
		{
			cout << input;
			break;
		}
		if (!arr[i])
			if (input%i == 0)
			{
				input = input / i;
				cout << i << endl;
			}
			else
				i++;
		else
			i++;
	}
}

int main()
{
	int input;
	cin >> input;
	int size = sqrt(input);
	eratosthenes(size);
	printprime(input, size);
	return 0;
}