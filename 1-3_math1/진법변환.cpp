#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string number;
	int sysnum;
	int num;
	int totalsum = 0;
	int sum = 0;
	cin >> number >> sysnum;
	for (int i = 0; i < number.size(); i++)
	{
		if (number[i] >= '0' && number[i] <= '9')
			num = number[i] - '0';
		else if (number[i] >= 'A' && number[i] <= 'Z')
			num = number[i] - 'A' + 10;
		sum = pow(sysnum, (number.size() - i - 1));
		totalsum += sum * num;
	}

	cout << totalsum;
	return 0;
}