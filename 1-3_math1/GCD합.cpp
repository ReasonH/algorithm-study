#include <iostream>
using namespace std;
int *arr;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}
long long sumgcd(int input)
{
	long long sum = 0;
	for (int i = 0; i < input-1; i++)
	{
		for (int j = i + 1; j < input; j++)
		{
			sum += gcd(arr[i], arr[j]);
		}
	}
	return sum;
}
int main()
{
	int testcase, input;
	cin >> testcase;
	while (testcase-- > 0)
	{
		cin >> input;
		arr = new int[input];
		for (int i = 0; i < input; i++)
		{
			cin >> arr[i];
		}
		cout << sumgcd(input) << endl;
	}
	return 0;
}