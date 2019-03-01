#include <iostream>
using namespace std;

int memo[12] = { 0 };
int calculater(int input)
{
	if (memo[input] != 0)
	{
		return memo[input];
	}
	if (input <= 3)
		switch (input)
		{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 4;
		default:
			break;
		}
	memo[input] = calculater(input - 3) + calculater(input - 2) + calculater(input - 1);
	return memo[input];
}
int main()
{
	int loop;
	cin >> loop;
	int input;
	for (int i = 0; i < loop; i++)
	{
		cin >> input;
		cout << calculater(input) << endl;
	}
	return 0;
}