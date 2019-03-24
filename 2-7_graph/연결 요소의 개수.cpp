#include <stdio.h>
#include <vector>
using namespace std;

void DFS(bool visit[], vector<int> *list, int v)
{
	visit[v] = true;
	for (int i = 0; i < list[v].size(); i++)
	{
		int next = list[v][i];
		if (visit[next] == false)
			DFS(visit, list, next);
	}
}

int main()
{
	int n, m;
	int cnt = 0;
	scanf_s("%d %d", &n, &m);
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
		if (!visit[i])
		{
			DFS(visit, list, i);
			cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}