#include <stdio.h>
#include <vector>
using namespace std;

int cnt;
bool done[100001];
void DFS(bool visit[], int list[], int startnum)
{
	visit[startnum] = true;
	int next = list[startnum];
	if (!visit[next])
	{
		DFS(visit, list, next);
	}
	else if (!done[next])
	{
		for (int i = next; i != startnum; i = list[i])
			cnt++;
		cnt++;
	}
	done[startnum] = true;
}
int main()
{
	int testcase, student, select;
	scanf_s("%d", &testcase);
	while (testcase--)
	{
		cnt = 0;
		scanf_s("%d", &student);
		int *list = new int[student + 1];
		bool *visit = new bool[student + 1];
		fill(visit, visit + student + 1, false);
		fill(done, done + student + 1, false);
		for (int i = 1; i <= student; i++)
		{
			scanf_s("%d", &select);
			list[i] = select;
		}
		for (int i = 1; i <= student; i++)
		{
			if (visit[i] == false)
			{
				DFS(visit, list, i);
			}
		}
		delete[] list;
		delete[] visit;
		printf("%d\n", student - cnt);
	}

	return 0;
}