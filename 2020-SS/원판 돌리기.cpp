#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int totalCircle;
int number;
bool findSame = false;
int mx[4]= { 1, 0, 0, -1 };
int my[4] = { 0, -1, 1, 0};
vector<vector<int>> wholeCircle;
void rotate(int circleNum, int direction, int step);
void DFS(bool **visit, int i, int j, bool recursiveChecker);
int main() {
	int rotation;
	cin >> totalCircle >> number >> rotation;

	// 초기 숫자 합과 원소의 갯수
	int total = 0;
	int currentElement = totalCircle * number;

	for (int i = 0; i < totalCircle; i++) {
		vector<int> eachCircle;
		for (int j = 0; j < number; j++) {
			int input;
			cin >> input;
			eachCircle.push_back(input);
			total += input;
		}
		wholeCircle.push_back(eachCircle);
	}

	// 총 회전 횟수만큼 반복
	for (int i = 0; i < rotation; i++) {
		int baseNumber;
		int direction;
		int step;
		cin >> baseNumber >> direction >> step;

		// base number로 몇 개의 원판이 선택 가능한지 본다
		int targetCount = totalCircle / baseNumber;
		for (int j = 1; j <= targetCount; j++) {
			// 각 원판을 회전시킨다
			rotate(j * baseNumber -1, direction, step);
		}

		// visit 초기화
		bool** visit = new bool*[totalCircle];
		for (int j = 0; j < totalCircle; j++) {
			visit[j] = new bool[number];
			for (int k = 0; k < number; k++) {
				visit[j][k] = false;
			}
		}

		// 현재 DFS 수행에서 Same이 있는가를 검사하는 변수
		findSame = false;
		for (int j = 0; j < totalCircle; j++)
		{
			for (int k = 0; k < number; k++)
			{
				if (!visit[j][k] && wholeCircle[j][k]) {
					DFS(visit, j, k, false);
				}
			}
		}
		
		// 0 division protection
		if (currentElement == 0) {
			total = 0;
			break;
		}
		float avg = (float)total / currentElement;
		total = 0;
		currentElement = 0;
		if (findSame) { // 인접행렬이 있다면 그냥 덧셈 수행
			for (vector<vector<int>>::iterator iter = wholeCircle.begin(); iter != wholeCircle.end(); iter++) {
				for (vector<int>::iterator iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
					if (*iter2 != 0) {
						total += *iter2;
						currentElement++;
					}
				}
			}
		}
		else { // 인접행렬을 못찾았다면 각 원소값 수정
			for (vector<vector<int>>::iterator iter = wholeCircle.begin(); iter != wholeCircle.end(); iter++) {
				for (vector<int>::iterator iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
					if (*iter2 != 0) {
						if (*iter2 > avg) {
							*iter2 = *iter2-1;
						}
						else if (*iter2 < avg) {
							*iter2 = *iter2+1;
						}
						total += *iter2;
						currentElement++;
					}
				}
			}
		}
	}
	cout << total;
}

// 원판 회전
void rotate(int circleNum, int direction, int step) {
	int size = wholeCircle[circleNum].size();
	int *arr = new int[size];
	if (direction == 0) { // 시계방향
		for (int i = 0; i < size; i++) {
			int nextpos = (i + step) % size;
			arr[nextpos] = wholeCircle[circleNum][i];
		}
	}
	else { // 반시계방향
		step = size - step;
		for (int i = 0; i < size; i++) {
			int nextpos = (i + step) % size;
			arr[nextpos] = wholeCircle[circleNum][i];
		}
	}

	// 회전 이전의 원판 -> 회전 이후 원판 모양으로 변경
	wholeCircle[circleNum].clear();
	for (int i = 0; i < size; i++) {
		wholeCircle[circleNum].push_back(arr[i]);
	}
}

// DFS
void DFS(bool **visit, int x, int y, bool recursiveChecker) {
	visit[x][y] = true; // 방문 표시
	for (int run = 0; run < 4; run++) {
		int nx = x + mx[run];
		int ny = y + my[run];
		if (ny == number) ny = 0;
		else if (ny < 0) ny = number - 1;
		if (nx == totalCircle) {
			continue;
		}
		if (nx == -1) {
			continue;
		}
		if ((wholeCircle[nx][ny] == wholeCircle[x][y]) && !visit[nx][ny] && wholeCircle[nx][ny]) {
			recursiveChecker = true;
			DFS(visit, nx, ny, recursiveChecker);
		}
	}
	// 현재 함수가 재귀호출이라면?
	if (recursiveChecker) {
		findSame = true; // 이번 DFS에서 인접하고 같은 수를 찾았다는 것으로 간주한다
		wholeCircle[x][y] = 0; // 재귀호출이 끝날 때 원판 숫자를 없앰 (숫자0은 X를 뜻함)
	}
}