#include <iostream>
using namespace std;

int memo[10] = { 1,1,1,1,1,1,1,1,1,1 };
int cache[10] = { 0 };

int Upnumber(int input)
{
	if (input == 1)
		return 10;
	for (int i = 1; i < input; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = j; k < 10; k++)
			{
				cache[k] = cache[k] + memo[j] % 10007;
			}
		}
		for (int j = 0; j < 10; j++)
		{
			memo[j] = cache[j] % 10007;
			cache[j] = 0;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += memo[i];
	}
	return (sum%10007);
}

int main()
{
	int input;
	cin >> input;
	cout << Upnumber(input);
	return 0;
}