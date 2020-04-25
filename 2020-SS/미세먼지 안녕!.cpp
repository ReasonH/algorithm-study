#include <iostream>
#include <queue>
using namespace std;

int room[51][51];
int newRoom[51][51];
vector<pair<int, int>> dust;

//상하좌우
int directorR[4] = { -1, 1, 0, 0 };
int directorC[4] = { 0, 0, -1, 1 };
int R, C, T;

// 공기청정기 위치
int uX;
int dX;

void spread();
void purificate();
int main() {
	vector<int> conditioner;
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> room[i][j];
			if (room[i][j] > 0) {
				dust.push_back(make_pair(i, j));
			}
			else if (room[i][j] == -1) {
				conditioner.push_back(i);
			}
		}
	}
	uX = conditioner[0];
	dX = conditioner[1];
	
	for (int i = 0; i < T; i++) {
		spread();
	}
	int total = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			total+=room[i][j];
		}
	}
	cout << total + 2; // 공기청정기 값 덧셈
	return 0;
}

// 공기 확장
void spread() {
	for(int i = 0; i < dust.size(); i++ ){
		int x = dust[i].first;
		int y = dust[i].second;
		int nowDust = room[x][y];
		int spreadSize = 0;
		for (int i = 0; i < 4; i++) {
			int newX = x + directorR[i];
			int newY = y + directorC[i];
			if (newX > 0 && newX <= R && newY > 0 && newY <= C) {
				if (room[newX][newY] != -1) {
					newRoom[newX][newY] += (nowDust / 5);
					spreadSize++;
				}
			}
		}
		newRoom[x][y] += (nowDust - (nowDust / 5) * spreadSize);
	}
	newRoom[uX][1] = -1;
	newRoom[dX][1] = -1;
	

	dust.clear();
	purificate();
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (newRoom[i][j] > 0) { // 먼지위치 저장
				dust.push_back(make_pair(i, j));
			}
			room[i][j] = newRoom[i][j];
			newRoom[i][j] = 0;
		}
	}
}

void purificate() {
	// 공기청정기 위치는 uX, dX이다
	for (int i = uX - 1; i > 0; i--) {
		newRoom[i + 1][1] = newRoom[i][1];
	}
	for (int i = dX + 1; i <= R; i++) {
		newRoom[i - 1][1] = newRoom[i][1];
	}
	for (int i = 2; i <= C; i++) {
		newRoom[1][i - 1] = newRoom[1][i];
		newRoom[R][i - 1] = newRoom[R][i];
	}
	for (int i = R - 1; i >= dX; i--) {
		newRoom[i + 1][C] = newRoom[i][C];
	}
	for (int i = 2; i <= uX; i++) {
		newRoom[i - 1][C] = newRoom[i][C];
	}
	for (int i = C-1; i > 1; i--) {
		newRoom[uX][i + 1] = newRoom[uX][i];
		newRoom[dX][i + 1] = newRoom[dX][i];
	}
	newRoom[uX][1] = -1;
	newRoom[dX][1] = -1;
	newRoom[uX][2] = 0;
	newRoom[dX][2] = 0;
}