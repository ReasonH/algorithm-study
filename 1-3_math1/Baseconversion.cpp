#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int arr[25] = { 0 };
vector<int> vec;
int main()
{
	int origin, conversion;
	int inputnum;
	cin >> origin >> conversion;
	cin >> inputnum;
	int decnum = 0;
	for (int i = 0; i < inputnum; i++)
	{
		cin >> arr[i];
		decnum += arr[i] * pow(origin, inputnum - 1 - i);
	}

	int maxdigit = 0;
	while (pow(conversion, maxdigit++) <= decnum) {}
	maxdigit--;
	int sum = 0;
	if (maxdigit == 0)
	{
		vec.push_back(0);
	}
	while (maxdigit-- > 0)
	{
		for (int i = 1; i <= conversion; i++)
		{
			if (i == conversion)
			{
				vec.push_back(0);
			}
			else if (sum + (conversion - i) * pow(conversion, maxdigit) <= decnum)
			{
				sum = sum + (conversion - i)*pow(conversion, maxdigit);
				vec.push_back((conversion - i));
				break;
			}
		}
	}

	vector<int>::iterator iter = vec.begin();  // 벡터 반복자 시작지점
	for (iter; iter != vec.end(); ++iter) {
		cout << *iter << ' ';
	}
	return 0;
}