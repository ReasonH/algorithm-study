#include <stdio.h>
#include <vector>
using namespace std;

bool check;
void DFS(int color[], vector<int> *list, int currentnode, int nowcolor)
{
	nowcolor = -nowcolor;
	color[currentnode] = nowcolor;
	for (int i = 0; i < list[currentnode].size(); i++)
	{
		int next = list[currentnode][i];
		if (color[next] == 0)
			DFS(color, list, next, nowcolor);
		if (color[next] == nowcolor)
		{
			check = true;
			break;
		}
	}
}

int main()
{
	int testcase, N, M, u, v;
	scanf_s("%d", &testcase);
	while (testcase--)
	{
		check = false;
		scanf_s("%d %d", &N, &M);
		vector<int> *list = new vector<int>[N + 1];
		bool *visit = new bool[N + 1];
		int *color = new int[N + 1];
		fill(color, color + N + 1, 0);
		for (int i = 0; i < M; i++)
		{
			scanf_s("%d %d", &u, &v);
			list[u].push_back(v);
			list[v].push_back(u);
		}
		for (int i = 1; i <= N; i++)
		{
			if (color[i] == 0)
				DFS(color, list, i, -1);
		}
		if (check)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}