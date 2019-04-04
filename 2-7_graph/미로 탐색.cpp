#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

bool check[100][100];
int stepinfo[100][100];
void BFS(string *line, int h, int w)
{
	queue<pair<int,int>> que;
	pair<int, int> p;
	p.first = 0;
	p.second = 0;
	que.push(p);
	check[0][0] = true;
	stepinfo[0][0] = 1;
	while (!que.empty())
	{
		int first = que.front().first;
		int second = que.front().second;
		que.pop();
		if (first -1 >= 0 && !check[first-1][second] && line[first-1][second] == '1')
		{
			pair<int, int> p;
			p.first = first-1;
			p.second = second;
			que.push(p);
			check[first-1][second] = true;
			stepinfo[first - 1][second] = stepinfo[first][second] + 1;
		}
		if (first +1 < h && !check[first + 1][second] && line[first + 1][second] == '1')
		{
			pair<int, int> p;
			p.first = first + 1;
			p.second = second;
			que.push(p);
			check[first + 1][second] = true;
			stepinfo[first + 1][second] = stepinfo[first][second] + 1;
		}
		if (second - 1 >= 0 && !check[first][second - 1] && line[first][second - 1] == '1')
		{
			pair<int, int> p;
			p.first = first;
			p.second = second - 1;
			que.push(p);
			check[first][second - 1] = true;
			stepinfo[first][second - 1] = stepinfo[first][second] + 1;
		}
		if (second + 1 < w && !check[first][second + 1] && line[first][second + 1] == '1')
		{
			pair<int, int> p;
			p.first = first;
			p.second = second + 1;
			que.push(p);
			check[first][second + 1] = true;
			stepinfo[first][second + 1] = stepinfo[first][second] + 1;
		}
		if (check[h - 1][w - 1])
		{
			cout << stepinfo[h-1][w-1];
			break;
		}
	}
}

int main()
{
	int h, w;
	cin >> h >> w;
	string *line = new string[h];
	fill(&check[0][0], &check[0][0] + 100 * 100, false);
	fill(&stepinfo[0][0], &stepinfo[0][0] + 100 * 100, 0);
	for (int i = 0; i < h; i++)
	{
		cin >> line[i];
	}
	BFS(line, h, w);

	return 0;
}