#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int people, total_time;
	scanf_s("%d", &people);
	int *time = new int[people];
	for (int i = 0; i < people; i++)
	{
		scanf_s("%d", &time[i]);
	}
	sort(time, time + people);
	total_time = 0;
	int pre_wait = 0;
	for (int i = 0; i < people; i++)
	{
		int temp = pre_wait + time[i];
		total_time += temp;
		pre_wait = temp;
	}
	printf("%d", total_time);
	return 0;
}