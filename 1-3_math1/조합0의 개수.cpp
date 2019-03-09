#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int two = 0, five = 0;
	for (long long int i = 2; i <= n; i *= 2)
	{
		two += n / i;
		if (i <= m)
		{
			two -= m / i;
		}
		if (i <= n - m)
		{
			two -= (n - m) / i;
		}
	}
	for (long long int i = 5; i <= n; i *= 5)
	{
		five += n / i;
		if (i <= m)
		{
			five -= m / i;
		}
		if (i <= n - m)
		{
			five -= (n - m) / i;
		}
	}
	
	cout << ((two < five) ? two : five);

	return 0;
}