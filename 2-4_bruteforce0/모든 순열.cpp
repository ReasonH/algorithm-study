#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

int main()
{
	int size;
	scanf_s("%d", &size);
	vector<int> per(size);
	for (int i = 0; i < size; i++)
		per[i] = i + 1;
	do {
		for (int i = 0; i < size; i++)
			printf("%d ", per[i]);
		printf("\n");
	} while (next_permutation(per.begin(), per.end()));
	return 0;
}