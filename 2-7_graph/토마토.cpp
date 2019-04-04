#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> *tomatto, vector<int> *daysinfo, int h, int w)
{
	int maxday = 0;
	queue<pair<int, int>> que;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (tomatto[i][j] == 1)
			{
				pair<int, int> p;
				p.first = i;
				p.second = j;
				que.push(p);
			}
		}
	}

	while (!que.empty())
	{
		int first = que.front().first;
		int second = que.front().second;
		int days = daysinfo[first][second];
		que.pop();
		if (first - 1 >= 0 && tomatto[first - 1][second] == 0)
		{
			pair<int, int> p;
			p.first = first - 1;
			p.second = second;
			que.push(p);
			tomatto[first - 1][second] = 1;
			daysinfo[first - 1][second] = days + 1;
			if (days + 1 > maxday)
				maxday = days + 1;
		}
		if (first + 1 < h && tomatto[first + 1][second] == 0)
		{
			pair<int, int> p;
			p.first = first + 1;
			p.second = second;
			que.push(p);
			tomatto[first + 1][second] = 1;
			daysinfo[first + 1][second] = days + 1;
			if (days + 1 > maxday)
				maxday = days + 1;
		}
		if (second - 1 >= 0 && tomatto[first][second-1] == 0)
		{
			pair<int, int> p;
			p.first = first;
			p.second = second-1;
			que.push(p);
			tomatto[first][second - 1] = 1;
			daysinfo[first][second-1] = days + 1;
			if (days + 1 > maxday)
				maxday = days + 1;
		}
		if (second + 1 < w && tomatto[first][second+1] == 0)
		{
			pair<int, int> p;
			p.first = first;
			p.second = second + 1;
			que.push(p);
			tomatto[first][second + 1] = 1;
			daysinfo[first][second + 1] = days + 1;
			if (days + 1 > maxday)
				maxday = days + 1;
		}
	}
	bool check = false;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (tomatto[i][j] == 0)
				check = true;
		}
	}
	if (check)
		printf("-1");
	else
		printf("%d", maxday);
}
int main()
{
	int h, w;
	scanf_s("%d %d", &w, &h);
	vector<int> *tomatto = new vector<int>[h];
	vector<int> *daysinfo = new vector<int>[h];
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int status;
			scanf_s("%d", &status);
			tomatto[i].push_back(status);
			daysinfo[i].push_back(0);
		}
	}
	BFS(tomatto, daysinfo, h, w);
	
	return 0;
}