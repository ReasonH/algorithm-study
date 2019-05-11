#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int size, negnum, posnum;
	scanf_s("%d", &size);
	int *number = new int[size];
	posnum = 0;
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &number[i]);
		if (number[i] > 0)
			posnum++;
	}
	sort(number, number + size);

	int total = 0;
	for (int i = 0; i < size-posnum;)
	{
		if (i + 1 == size-posnum)
		{
			total += number[i];
			i++;
		}
		else
		{
			total += number[i] * number[i + 1];
			i += 2;
		}
	}
	for (int i = 1; i <= posnum;)
	{
		if (i + 1 > posnum)
		{
			total += number[size - i];
			i++;
		}
		else
		{
			if (number[size - i] == 1 || number[size - i - 1] == 1)
				total += number[size - i] + number[size - i - 1];
			else
				total += number[size - i] * number[size - i - 1];
			i += 2;
		}
	}
	printf("%d", total);
	return 0;
}