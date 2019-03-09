#include <iostream>
using namespace std;

int main()
{
	int number;
	cin >> number;
	double sum = 1;
	for (int i = 2; i <= number; i++)
	{
		sum *= i;
	}
	cout << sum;
	return 0;
}