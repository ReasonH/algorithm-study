#include <stdio.h>
#include <vector>
using namespace std;

int island = 0;
int map[51][51] = { 0 };
bool check[51][51];
int w = 0;
int h = 0;
void DFS(int i, int j)
{
	check[i][j] = true;
	if(i+1 <= h && check[i+1][j] == false && map[i+1][j] == 1)
		DFS(i + 1, j);
	if(i-1 >= 1 && check[i-1][j] == false && map[i - 1][j] == 1)
		DFS(i - 1, j);
	if(j+1 <= w && check[i][j + 1] == false && map[i][j + 1] == 1)
		DFS(i, j + 1);
	if(j-1 >= 1 && check[i][j - 1] == false && map[i][j - 1] == 1)
		DFS(i, j - 1);
	if (j + 1 <= w && i + 1 <= h && check[i + 1][j + 1] == false && map[i + 1][j + 1] == 1)
		DFS(i + 1, j + 1);
	if (j - 1 >= 1 && i + 1 <= h && check[i + 1][j - 1] == false && map[i + 1][j - 1] == 1)
		DFS(i + 1, j - 1);
	if (i - 1 >= 1 && j + 1 <= w && check[i - 1][j + 1] == false && map[i - 1][j + 1] == 1)
		DFS(i - 1, j + 1);
	if (i - 1 >= 1 && j - 1 >= 1 && check[i - 1][j - 1] == false && map[i - 1][j - 1] == 1)
		DFS(i - 1, j - 1);
}

int main()
{
	while (true)
	{
		island = 0;
		scanf_s("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;
		fill(&check[0][0], &check[0][0]+51*51, false);
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				scanf_s("%d", &map[i][j]);
			}
		}
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				if (check[i][j] == false && map[i][j] == 1)
				{
					DFS(i, j);
					island++;
				}
				else if (check[i][j] == false && map[i][j] == 0)
					check[i][j] = true;
			}
		}
		printf("%d\n", island);
	}
	return 0;
}
