#include <stdio.h>
using namespace std;

int main()
{
	int N, M;
	scanf_s("%d %d", &N, &M);
	int count = 1;
	if (N == 1)
		count = 1;
	else if (N == 2)
	{
		if (M < 9)
			count += (M - 1) / 2;
		else
			count = 4;
	}
	else
	{
		if (M < 5)
			count += (M - 1);
		else if (M > 6)
		{
			count += 4;
			count += (M - 7);
		}
		else
			count += 3;
	}
	printf("%d", count);
	return 0;
}