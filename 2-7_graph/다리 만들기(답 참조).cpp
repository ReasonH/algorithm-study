#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int minlength = 0;
vector<vector<pair<int, int>>> land;
vector<pair<int, int>> temp;
int mininum = 9999;
void DFS(vector<int> *map, bool landNumcheck[][100], int i, int j)
{
	temp.push_back(make_pair(i, j));
	landNumcheck[i][j] = true;
	if (i - 1 >= 0 && !landNumcheck[i - 1][j] && map[i - 1][j] == 1)
	{
		DFS(map, landNumcheck, i - 1, j);
	}
	if (i + 1 < map->size() && !landNumcheck[i + 1][j] && map[i + 1][j] == 1)
	{
		DFS(map, landNumcheck, i + 1, j);
	}
	if (j - 1 >= 0 && !landNumcheck[i][j - 1] && map[i][j - 1] == 1)
	{
		DFS(map, landNumcheck, i, j - 1);
	}
	if (j + 1 < map->size() && !landNumcheck[i][j + 1] && map[i][j + 1] == 1)
	{
		DFS(map, landNumcheck, i, j + 1);
	}
}
void calculate(int landnum)
{
	for (int i = 0; i < landnum; i++)
	{
		for (int j = 0; j < land[i].size(); j++)
		{
			for (int k = i + 1; k < landnum; k++)
			{
				for (int m = 0; m < land[k].size(); m++)
				{
					int x1 = land[i][j].first;
					int y1 = land[i][j].second;
					int x2 = land[k][m].first;
					int y2 = land[k][m].second;
					mininum = min(abs(x1 - x2)+abs(y1 - y2)-1, mininum);
				}
			}
		}
	}
}

int main()
{
	int mapsize;
	scanf_s("%d", &mapsize);
	vector<int> *map = new vector<int>[mapsize];
	bool landNumcheck[100][100];
	fill(&landNumcheck[0][0], &landNumcheck[0][0] + 100 * 100, false);
	for (int i = 0; i < mapsize; i++)
	{
		for (int j = 0; j < mapsize; j++)
		{
			int LandorSea;
			scanf_s("%d", &LandorSea);
			map[i].push_back(LandorSea);
		}
	}
	int landcnt = 0;
	for (int i = 0; i < mapsize; i++)
	{
		for (int j = 0; j < mapsize; j++)
		{
			if (!landNumcheck[i][j]&& map[i][j] == 1)
			{
				temp.clear();
				DFS(map, landNumcheck, i, j);
				land.push_back(temp);
				landcnt++; // ÀÏ´Ü °¢ ¼¶µé³¢¸® ¹­¾îÁØ´Ù
			}
		}
	}
	calculate(landcnt);
	printf("%d", mininum);
	return 0;
}