#include <iostream>
using namespace std;

int memo[1001] = { 0 };
int number;
int *price = new int[number];
int expensive(int input)
{
	if (input == 0)
		return 0;
	if (memo[input] != 0)
		return memo[input];
	for (int i = 1; i <= input/2; i++)
	{
		if(memo[input] == 0)
			memo[input] = price[input - 1];
		if (memo[input] < expensive(input - i) + expensive(i))
			memo[input] = expensive(input - i) + expensive(i);
	}
	return memo[input];
}
int main()
{
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		cin >> price[i];
	}
	memo[1] = price[0];
	cout << expensive(number);

	return 0;
}