#include <iostream>
using namespace std;

int memo[1001] = { 0 };
void calculater(int input)
{
	for (int i = 3; i <= input; i++)
	{
		memo[i] = (memo[i - 1] + memo[i - 2] * 2) % 10007;
	}
}
int main()
{
	memo[1] = 1;
	memo[2] = 3;
	int input;
	cin >> input;
	calculater(input);
	cout << memo[input];
	return 0;
}