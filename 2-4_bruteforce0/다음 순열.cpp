#include <stdio.h>
#include <algorithm>
using namespace std;

int sequence[10001] = { 0 };
int main()
{
	int input;
	scanf_s("%d", &input);
	for (int i = 1; i <= input; i++)
	{
		scanf_s("%d", &sequence[i]);
	}

	int max = 0;
	bool change = false;
	int indexcheck = 0;
	int sortindex = 0;
	for (int i = 1; i < input; i++)
	{
		max = 10001;
		for (int j = 1; j <= i; j++)
		{
			if (sequence[input - i] < sequence[input - i + j] && sequence[input - i + j] < max)
			{
				max = sequence[input - i + j];
				indexcheck = input - i + j;
			}
		}
		if (max != 10001)
		{
			change = true;
			sortindex = input - i;
			int temp = sequence[input - i];
			sequence[input - i] = sequence[indexcheck];
			sequence[indexcheck] = temp;
			break;
		}
	}

	if (change)
	{
		sort(sequence + sortindex + 1, sequence + input + 1);
		for (int i = 1; i <= input; i++)
		{
			printf("%d ", sequence[i]);
		}
	}
	else
		printf("-1");
	return 0;
}