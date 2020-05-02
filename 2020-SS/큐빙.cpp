#include <iostream>
#include <string>
using namespace std;

char cube[7][10];
string input;
int N;

void updown(int plane, int rotate);
void frontback(int plane, int rotate);
void leftright(int plane, int rotate);
void print();
void init();
int main() {
	cin >> N;
	int M = 0;
	for (int i = 0; i < N; i++) {
		init();
		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> input;

			int rotate = 0; // 회전 횟수 지정
			if (input[1] == '+') {
				rotate = 1;
			}
			else {
				rotate = 3;
			}

			switch (input[0])
			{
			case 'U':
				updown(1, rotate);
				break;
			case 'D':
				updown(2, rotate);
				break;
			case 'F':
				frontback(3, rotate);
				break;
			case 'B':
				frontback(4, rotate);
				break;
			case 'L':
				leftright(5, rotate);
				break;
			case 'R':
				leftright(6, rotate);
				break;
			default:
				break;
			}
		}
		print();
	}
	return 0;
}

void print() {
	for (int i = 1; i <= 9; i++) {
		cout << cube[1][i];
		if (i % 3 == 0) {
			cout << endl;
		}
	}
}

void init() {
	// 위, 아래, 앞, 뒤, 왼쪽, 오른쪽
	char color[7] = { ' ', 'w', 'y', 'r', 'o', 'g', 'b' };
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 9; j++) {
			cube[i][j] = color[i];
		}
	}
}

void planerotate(int plane) {
	char temp = cube[plane][1];
	cube[plane][1] = cube[plane][7];
	cube[plane][7] = cube[plane][9];
	cube[plane][9] = cube[plane][3];
	cube[plane][3] = temp;
	char temp2 = cube[plane][2];
	cube[plane][2] = cube[plane][4];
	cube[plane][4] = cube[plane][8];
	cube[plane][8] = cube[plane][6];
	cube[plane][6] = temp2;
}

void updown(int plane, int rotate) {
	if (plane == 1) {
		for (int i = 0; i < rotate; i++) {
			char temp[10];
			for (int i = 1; i <= 3; i++) {
				temp[i] = cube[4][i]; // 임시 저장
			}
			for (int j = 1; j <= 3; j++) {
				cube[4][j] = cube[5][j];
				cube[5][j] = cube[3][j];
				cube[3][j] = cube[6][j];
				cube[6][j] = temp[j];
			}
			planerotate(plane);
		}
	}
	else {
		for (int i = 0; i < rotate; i++) {
			char temp[10];
			for (int i = 7; i <= 9; i++) {
				temp[i] = cube[4][i]; // 임시 저장
			}
			for (int j = 7; j <= 9; j++) {
				cube[4][j] = cube[6][j];
				cube[6][j] = cube[3][j];
				cube[3][j] = cube[5][j];
				cube[5][j] = temp[j];
			}
			planerotate(plane);
		}
	}
}

void frontback(int plane, int rotate) {
	if ( plane == 3 ) { // 프론트
		for (int i = 0; i < rotate; i++) {
			char temp[10];
			for (int i = 1; i <= 9; i++) {
				temp[i] = cube[1][i]; // 임시 저장
			}
			cube[1][7] = cube[5][9];
			cube[1][8] = cube[5][6];
			cube[1][9] = cube[5][3];

			cube[5][9] = cube[2][7];
			cube[5][6] = cube[2][8];
			cube[5][3] = cube[2][9];

			cube[2][7] = cube[6][1];
			cube[2][8] = cube[6][4];
			cube[2][9] = cube[6][7];

			cube[6][1] = temp[7];
			cube[6][4] = temp[8];
			cube[6][7] = temp[9];
			planerotate(plane);
		}
	}
	else { // 백
		for (int i = 0; i < rotate; i++) {
			char temp[10];
			for (int i = 1; i <= 9; i++) {
				temp[i] = cube[1][i]; // 임시 저장
			}
			cube[1][1] = cube[6][3];
			cube[1][2] = cube[6][6];
			cube[1][3] = cube[6][9];

			cube[6][3] = cube[2][1];
			cube[6][6] = cube[2][2];
			cube[6][9] = cube[2][3];

			cube[2][1] = cube[5][7];
			cube[2][2] = cube[5][4];
			cube[2][3] = cube[5][1];

			cube[5][7] = temp[1];
			cube[5][4] = temp[2];
			cube[5][1] = temp[3];
			planerotate(plane);
		}
	}
}

void leftright(int plane, int rotate) {
	if ( plane == 5 ) { // 레프트
		for (int i = 0; i < rotate; i++) {
			char temp[10];
			for (int i = 1; i <= 9; i++) {
				temp[i] = cube[1][i]; // 임시 저장
			}
			cube[1][1] = cube[4][9];
			cube[1][4] = cube[4][6];
			cube[1][7] = cube[4][3];

			cube[4][9] = cube[2][9];
			cube[4][6] = cube[2][6];
			cube[4][3] = cube[2][3];

			cube[2][9] = cube[3][1];
			cube[2][6] = cube[3][4];
			cube[2][3] = cube[3][7];

			cube[3][1] = temp[1];
			cube[3][4] = temp[4];
			cube[3][7] = temp[7];
			planerotate(plane);
		}
	}
	else { // 라이트
		for (int i = 0; i < rotate; i++) {
			char temp[10];
			for (int i = 1; i <= 9; i++) {
				temp[i] = cube[1][i]; // 임시 저장
			}
			cube[1][3] = cube[3][3];
			cube[1][6] = cube[3][6];
			cube[1][9] = cube[3][9];

			cube[3][3] = cube[2][7];
			cube[3][6] = cube[2][4];
			cube[3][9] = cube[2][1];

			cube[2][7] = cube[4][7];
			cube[2][4] = cube[4][4];
			cube[2][1] = cube[4][1];

			cube[4][7] = temp[3];
			cube[4][4] = temp[6];
			cube[4][1] = temp[9];
			planerotate(plane);
		}
	}
}