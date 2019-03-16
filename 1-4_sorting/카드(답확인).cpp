#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int size;
	long long max;
	scanf_s("%d", &size);
	long long *cardarr = new long long[size+1];
	for (int i = 1; i <= size; i++)
	{
		scanf_s("%lld", &cardarr[i]);
	}
	sort(cardarr + 1, cardarr + size +1);
	int cnt = 1;
	int maxcnt = 1;
	max = cardarr[1];
	for (int i = 2; i <= size; i++)
	{
		if (cardarr[i] == cardarr[i - 1])
		{
			cnt++;
		}
		else // 수열의 수가 바뀔 경우
		{
			if (cnt > maxcnt) // 기존 maxcnt 값보다 cnt가 클 때
			{
				maxcnt = cnt; // cnt를 maxcnt로 하고
				max = cardarr[i - 1]; // max를 이전 카드넘버로
			}
			cnt = 1;
		}
		if (i == size)
		{
			if (cnt > maxcnt) // 기존 maxcnt 값보다 cnt가 클 때
			{
				maxcnt = cnt; // cnt를 maxcnt로 하고
				max = cardarr[i - 1]; // max를 이전 카드넘버로
			}
		}
	}
	printf("%lld", max);
	return 0;
}