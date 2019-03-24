#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void BFS(bool visit[], vector<int> *list, int v)
{
	queue<int> que;
	que.push(v);
	visit[v] = true;
	while (!que.empty())
	{
		int qfront = que.front();
		printf("%d ", qfront);
		que.pop();
		for (int i = 0; i < list[qfront].size(); i++)
		{
			if (!visit[list[qfront][i]])
			{
				que.push(list[qfront][i]);
				visit[list[qfront][i]] = true;
			}
		}
	}
}

void DFS(bool visit[], vector<int> *list, int v)
{
	visit[v] = true;
	printf("%d ", v);
	for (int i = 0; i < list[v].size(); i++)
	{
		int next = list[v][i];
		if (visit[next] == false)
			DFS(visit, list, next);
	}
}

int main()
{
	int n, m, v;
	scanf_s("%d %d %d", &n, &m, &v);
	vector<int> *list = new vector<int>[n + 1];
	bool *visit = new bool[n + 1];
	fill(visit, visit + n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int num1, num2;
		scanf_s("%d %d", &num1, &num2);
		list[num1].push_back(num2);
		list[num2].push_back(num1);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(list[i].begin(), list[i].end());
	}
	DFS(visit, list, v);
	fill(visit, visit + n + 1, false);
	printf("\n");
	BFS(visit, list, v);
	return 0;
}