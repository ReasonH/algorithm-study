#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int size, order;
	scanf_s("%d %d", &size, &order);
	long long *arr = new long long[size];
	for (int i = 0; i < size; i++)
	{
		scanf_s("%lld", &arr[i]);
	}
	sort(arr, arr + size);
	printf("%d", arr[order - 1]);
	return 0;
}