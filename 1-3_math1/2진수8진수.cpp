#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	string binarynum;
	cin >> binarynum;
	int size = binarynum.size();
	int i = 0;
	int num = 0;
	char temp;
	string result;
	while (i < size)
	{
		temp = binarynum[size - i -1];
		if (temp == '1')
			num += 1 * pow(2, (i % 3));
		else
			num += 0;
		i++;
		if (i % 3 == 0)
		{
			result += char(num + '0');
			num = 0;
		}
		if (i % 3 != 0 && i == size)
		{
			result += char(num + '0');
		}
	}

	reverse(result.begin(), result.end());
	cout << result;
	return 0;
}