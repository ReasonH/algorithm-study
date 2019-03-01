#include <iostream>
using namespace std;

int arr[100];
int main()
{
	int inputnum;
	cin >> inputnum;
	int num = 0;
	for (int i = 0; i < inputnum; i++)
	{
		cin >> arr[i];
		if (arr[i] == 2)
			num++;
		if (arr[i] % 2 != 0)
		{
			for (int j = 3; j <= arr[i]; j++)
			{
				if (arr[i] == j)
					num++;
				else if (arr[i] % j == 0)
					break;
			}
		}
	}

	cout << num;
	return 0;
}