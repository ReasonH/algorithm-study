#include <iostream>
using namespace std;

int memo[1001] = { 0 };
int calculater(int input)
{
	if (input < 3)
	{
		return memo[input];
	}
	if (memo[input] != 0)
	{
		return memo[input];
	}
	memo[input] = (calculater(input - 1) + calculater(input - 2)) % 10007;

	return memo[input];
}
int main()
{
	memo[1] = 1;
	memo[2] = 2;
	int input;
	cin >> input;
	cout << calculater(input);
	return 0;
}