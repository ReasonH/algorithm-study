#include <iostream>
#include <algorithm>
using namespace std;

#define maxSize 1000001
int cache[maxSize] = { 0 };

int makeOne(int input)
{
	for (int i = 2; i <= input; i++)
	{
		cache[i] = cache[i - 1] + 1;
		if (i % 2 == 0)
			cache[i] = min(cache[i], cache[i / 2] + 1);
		if (i % 3 == 0)
			cache[i] = min(cache[i], cache[i / 3] + 1);
	}
	return cache[input];
}

int main()
{
	int input;
	cin >> input;
	cout << makeOne(input) << endl;

	return 0;
}