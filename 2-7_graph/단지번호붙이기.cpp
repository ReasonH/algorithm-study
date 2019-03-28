#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int part = 0;
void DFS(bool check[][25], string *list, int i, int j, int row)
{
	check[i][j] = true;
	part++;
	if(i+1 < row && check[i+1][j] == false && list[i+1][j] == '1')
		DFS(check, list, i + 1, j, row);
	if(i-1 >=0 && check[i-1][j] == false && list[i - 1][j] == '1')
		DFS(check, list, i - 1, j, row);
	if(j+1 < row && check[i][j + 1] == false && list[i][j + 1] == '1')
		DFS(check, list, i, j + 1, row);
	if(j-1 >= 0 && check[i][j - 1] == false && list[i][j - 1] == '1')
		DFS(check, list, i, j - 1, row);
}
int main()
{
	int row, cnt;
	cnt = 0;
	cin >> row;
	string *apart = new string[row];
	bool check[25][25];
	fill(&check[0][0], &check[0][0]+25*25, false);
	vector<int> apart_line;
	for (int i = 0; i < row; i++)
	{
		cin >> apart[i];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (check[i][j] == false && apart[i][j] == '1')
			{
				DFS(check, apart, i, j, row);
				apart_line.push_back(part);
				part = 0;
			}
			else if (check[i][j] == false && apart[i][j] == '0')
				check[i][j] = true;
		}
	}
	sort(apart_line.begin(), apart_line.end());
	cout << apart_line.size() << endl;
	for (int i = 0; i< apart_line.size(); i++)
	{
		cout << apart_line[i] << endl;;
	}
}