#include <iostream>
#include <vector>
using namespace std;

struct shark {
	int r;
	int c;
	int s; // 속력
	int d; // 방향 - 상하우좌
	int z; // 크기
};
int directorX[5] = { 0, -1, 1, 0, 0 };
int directorY[5] = { 0, 0, 0, 1, -1 };

bool map[101][101]; // 상어 유무 표시
shark sharkmap[101][101]; // 상어 지도
int R;
int C;
int sharks;
int point = 0;

void fishing();
void sharkmoving();
int main() {
	fill(&map[0][0], &map[100][101], false);
	cin >> R >> C >> sharks;
	int r;
	int c;
	int s;
	int d;
	int z;
	for (int i = 0; i < sharks; i++) {
		cin >> r >> c >> s >> d >> z;
		shark one;
		one.r = r;
		one.c = c;
		one.s = s;
		one.d = d;
		one.z = z;

		map[r][c] = true;
		sharkmap[r][c] = one;
	}
	fishing();
	cout << point;
}

void fishing() {
	for (int i = 1; i <= C; i++) {
		for (int j = 1; j <= R; j++) {
			if (map[j][i]) { // 상어가 있으면?
				point += sharkmap[j][i].z;
				map[j][i] = false;
				sharkmap[j][i].z = 0; // 상어가 없음을 나타냄
				break; // 잡고 턴이 끝난다.
			}
		}
		// 상어 이동
		sharkmoving();
	}
}

void sharkmoving() {
	vector<shark> aftermove;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j]) { // 상어가 있는 경우
				shark temp = sharkmap[i][j];
				temp.r = temp.r + (temp.s % ((R - 1) * 2)) * directorX[temp.d];
				temp.c = temp.c + (temp.s % ((C - 1) * 2)) * directorY[temp.d];
				while (temp.r > R || temp.r < 1 || temp.c > C || temp.c < 1) {
					if (temp.r > R) {
						temp.r = R - (temp.r - R);
						temp.d = 1;
					}
					else if (temp.r < 1) {
						temp.r = 1 + (1 - temp.r);
						temp.d = 2;
					}

					if (temp.c > C) {
						temp.c = C - (temp.c - C);
						temp.d = 4;
					}
					else if (temp.c < 1) {
						temp.c = 1 + (1 - temp.c);
						temp.d = 3;
					}
				}
				map[i][j] = false;
				aftermove.push_back(temp); // 이동한 이후 상어 위치, 방향 정보 등록
			}
		}
	}
	// 상어 재배치
	fill(&map[0][0], &map[100][101], false);
	for (int i = 0; i < aftermove.size(); i++) {
		int x = aftermove[i].r;
		int y = aftermove[i].c;
		// 새로운 위치에 상어가 들어가는 경우 map, sharkmap 세팅
		if (map[x][y] == true) {
			if (sharkmap[x][y].z < aftermove[i].z) {
				sharkmap[x][y] = aftermove[i];
			}
		}
		else {
			map[x][y] = true;
			sharkmap[x][y] = aftermove[i];
		}
	}
}