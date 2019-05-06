#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second < b.second)
		return true;
	else if (a.second == b.second)
		return a.first < b.first;
	else
		return false;
}
int main()
{
	int meeting_num;
	scanf_s("%d", &meeting_num);
	pair<int, int> *time = new pair<int, int>[meeting_num];
	for (int i = 0; i < meeting_num; i++)
	{
		scanf_s("%d %d", &time[i].first, &time[i].second);
	}
	sort(time, time + meeting_num, compare);
	int max_meeting = 0;
	int pre_meeting_end = 0;
	for (int i = 0; i < meeting_num; i++)
	{
		if (pre_meeting_end <= time[i].first)
		{
			pre_meeting_end = time[i].second;
			max_meeting++;
		}
	}
	printf("%d", max_meeting);

	return 0;
}