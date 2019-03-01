#include <iostream>
using namespace std;

long long memo[91][2] = { 0 };
void pinary(int input)
{
	int cache[2] = { 0 };
	if (input == 1)
		return;
	for (int i = 2; i <= input; i++)
	{
		memo[i][0] = memo[i-1][0] + memo[i-1][1];
		memo[i][1] += memo[i-1][0];
	}
}
int main()
{
	int number = 0;
	cin >> number;
	memo[1][1] = 1;
	pinary(number);
	cout << memo[number][0] + memo[number][1];
	return 0;
}