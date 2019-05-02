#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int size;
	cin >> size;
	vector<int> per(size);
	for (int i = 0; i < size; i++)
	{
		cin >> per[i];
	}
	if (prev_permutation(per.begin(), per.end()))
	{
		for (int i = 0; i < size; i++)
			cout << per[i] << ' ';
	}
	else
		cout << "-1";
	return 0;
}