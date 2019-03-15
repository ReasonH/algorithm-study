#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int size;
	scanf_s("%d", &size);
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	sort(arr, arr + size);
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}