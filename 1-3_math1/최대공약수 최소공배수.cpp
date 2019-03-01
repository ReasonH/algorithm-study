#include <iostream>
using namespace std;

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
int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << ' ' << a * b / gcd(a, b);
	return 0;
}