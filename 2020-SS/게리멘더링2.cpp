#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int least = 100000;
int N;
int map[21][21];
int electionArea[21][21] = { 0 };
int area[5] = { 0 };
void checkBoundaryLength(int x, int y);
void checkArea5Boundary(int x, int y, int d1, int d2);
void checkArea5();
void checkAreas(int x, int y, int d1, int d2);
int calculate();
vector<int> edges;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	
	// map의 좌상 -> 우하 기준점 x, y 설정
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			checkBoundaryLength(i, j);
		}
	}

	cout << least;
	return 0;
}

// 기준점 x, y에 대해 적절한 경계선 값 d1, d2를 찾는다
void checkBoundaryLength(int x, int y) {
	for (int d1 = 1; d1 < N - 1; d1++) {
		for (int d2 = 1; d2 < N - 1; d2++) {
			if ((x + d1 + d2) <= N && (1 <= (y - d1)) && (y + d2) <= N) {
				checkArea5Boundary(x, y, d1, d2);
			}
		}
	}
}

// 조건에 맞는 d1, d2로부터 선거구 5번의 영역 경계를 얻는다
void checkArea5Boundary(int x, int y, int d1, int d2) {
	edges.push_back(x); // top X
	edges.push_back(x + d1 + d2); // bottom

	electionArea[x][y] = 5;
	for (int i = 1; i <= d1; i++) { 
		electionArea[x + i][y - i] = 5;
	}
	for (int i = 1; i <= d2; i++) {
		electionArea[x + i][y + i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		electionArea[x + d1 + i][y - d1 + i] = 5;
	}
	for (int i = 0; i <= d1; i++) {
		electionArea[x + d2 + i][y + d2 - i] = 5;
	}

	checkArea5();
	checkAreas(x, y, d1, d2);
	least = min(least, calculate());

	edges.clear(); // 경계 꼭짓점 초기화
	fill(&electionArea[0][0], &electionArea[20][21], 0); // 선거구 정보 초기화
}

// 5번 구역 경계 내의 선거구를 5번 선거구로 변경한다
void checkArea5() {
	for (int i = 1; i <= N; i++) {
		bool flag = false;
		for (int j = 1; j <= N; j++) {
			if (i > edges[0] && i < edges[1]) {
				if (electionArea[i][j] == 5) {
					flag = !flag;
				}
			}
			if (flag) { // 플래그 켜진 경우 5로 바꿈
				electionArea[i][j] = 5;
			} // 플래그를 찾아본다.
		}
	}
}

void checkAreas(int x, int y, int d1, int d2) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (electionArea[i][j] != 5) {
				if (i < x + d1 && j <= y) {
					electionArea[i][j] = 1;
				}
				else if (i <= x + d2 && j > y) {
					electionArea[i][j] = 2;
				}
				else if (i >= x + d1 && j < y - d1 + d2) {
					electionArea[i][j] = 3;
				}
				else if (i > x + d2 && j >= y - d1 + d2) {
					electionArea[i][j] = 4;
				}
			}
		}
	}
}

int calculate() {
	vector<int> num(5, 0);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			num[electionArea[i][j]-1] += map[i][j];
		}
	}
	int maximum = 0;
	int minimum = 100000;
	for (int people : num) {
		if (maximum < people) {
			maximum = people;
		}
		if (minimum > people) {
			minimum = people;
		}
	}

	return maximum - minimum;
}