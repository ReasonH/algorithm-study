#include <iostream>
#include <algorithm>
using namespace std;

int cache[10001][3] = { 0 };
int wine[10001] = { 0 };
void maxwine(int gnumber)
{
	for (int i = 1; i <= gnumber; i++)
	{
		cache[i][0] = max(cache[i - 1][2], max(cache[i - 1][0], cache[i - 1][1]));
		cache[i][1] = cache[i - 1][0] + wine[i];
		cache[i][2] = cache[i - 1][1] + wine[i];
	}
	cout << max(cache[gnumber][0], max(cache[gnumber][1], cache[gnumber][2]));
}

int main()
{
	int gnumber;
	cin >> gnumber;
	for (int i = 1; i <= gnumber; i++)
	{
		cin >> wine[i];
	}
	maxwine(gnumber);
	return 0;
}