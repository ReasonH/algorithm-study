#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int arr[10001] = { 0 };
	int size, location;
	scanf_s("%d", &size);
	for (int i = 1; i <= size; i++)
	{
		scanf_s("%d", &location);
		arr[location]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] != 0)
		{
			for (int j = 0; j < arr[i]; j++)
				printf("%d\n", i);
		}
	}
	return 0;
}