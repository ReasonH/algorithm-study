#include <iostream>
#include <queue>
using namespace std;

bool visit[51][51];
int A[51][51];
int directorX[4] = { -1, 1, 0, 0 };
int directorY[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> que;
int N;
int L;
int R;
bool flag;

void setUnion();
int main() {
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	int move = 0;
	do{
		flag = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				visit[i][j] = false;
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!visit[i][j]) {
					visit[i][j] = true;
					que.push(make_pair(i, j));
					setUnion();
				}
			}
		}
		if (flag) {
			move++;
		}
	} while (flag);

	cout << move;
	return 0;
}

// 연합을 찾고 연합 인구수를 저장
void setUnion() {
	bool innerFlag = false;
	int total = 0;
	vector<pair<int, int>> uni;
	while (!que.empty()) {
		int r = que.front().first;
		int c = que.front().second;
		uni.push_back(make_pair(r, c)); // 유니온 추가
		total += A[r][c]; // 유니온 총인구 추가
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + directorX[i];
			int nc = c + directorY[i];
			if (nr > 0 && nr <= N && nc > 0 && nc <= N) {
				if (abs(A[r][c] - A[nr][nc]) >= L && abs(A[r][c] - A[nr][nc]) <= R && !visit[nr][nc]) {
					flag = true;
					innerFlag = true;
					visit[nr][nc] = true; // 나중에 BFS돌지 않도록함
					que.push(make_pair(nr, nc));
				}
			}
		}
	}
	if (innerFlag) {
		cout << total << ' ' << uni.size() << endl;

		int avg = total / uni.size();
		for (pair<int, int> location : uni) {
			A[location.first][location.second] = avg;
		}
	}
}