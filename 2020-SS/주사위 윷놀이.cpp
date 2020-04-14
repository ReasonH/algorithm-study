#include <stdio.h>
#include <algorithm>
using namespace std;

int dice[10];
int maxscore = 0;

// 2차원 배열의 행은 각 위치의 번호
// 2차원 배열의 0번열은 각 위치에서 얻을 수 있는 점수
// 2차원 배열의 나머지 열은 각 위치에서 갈 수 있는 위치

int jump[33][6] = { 
	{0,1,2,3,4,5}, 
	{2,2,3,4,5,9},
	{4,3,4,5,9,10},
	{6,4,5,9,10,11},
	{8,5,9,10,11,12},
	{10,6,7,8,20,29},
	{13,7,8,20,29,30},
	{16,8,20,29,30,31},
	{19,20,29,30,31,32}, 
	{12,10,11,12,13,14},
	{14,11,12,13,14,15}, 
	{16,12,13,14,15,16},
	{18,13,14,15,16,17}, 
	{20,18,19,20,29,30},
	{22,15,16,17,24,25}, 
	{24,16,17,24,25,26}, 
	{26,17,24,25,26,27}, 
	{28,24,25,26,27,28}, 
	{22,19,20,29,30,31}, 
	{24,20,29,30,31,32},
	{25,29,30,31,32,32},
	{26,20,29,30,31,32},
	{27,21,20,29,30,31},
	{28,22,21,20,29,30},
	{30,23,22,21,20,29},
	{32,26,27,28,31,32},
	{34,27,28,31,32,32}, 
	{36,28,31,32,32,32}, 
	{38,31,32,32,32,32},
	{30,30,31,32,32,32},
	{35,31,32,32,32,32}, 
	{40,32,32,32,32,32}, 
	{0,32,32,32,32,32}
};

void findMaxScore(int bit) {
	int score = 0;
	int occupation[33];
	int pos[4] = { 0,0,0,0 };
	fill(occupation, occupation + 33, 0);
	for (int turn = 0; turn < 10; turn++) {
		// 20자리 비트에서 2비트씩 자르면
		// 00,01,10,11 4종류를 얻을 수 있음 -> 각 주사위에서 선택하는 말의 번호 표현
		int marker = (bit >> (turn * 2)) & 0x3;
		
		int current_pos = pos[marker];
		int next_pos = jump[current_pos][dice[turn]];
		if (occupation[next_pos] == 1 && pos[marker] != 32) {
			return;
		}
		else {
			score += jump[next_pos][0];
			pos[marker] = next_pos;
			occupation[next_pos] = 1;
			occupation[current_pos] = 0;
		}
	}
	maxscore = max(score, maxscore);
}

int main()
{
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &dice[i]);
	}
	// 20자리 비트는 4^10 즉, 1~4번 말을 총 10번 움직이는 모든 경우를 나타냄
	for (int bit = 0; bit < (1 << 20); bit++) {
		findMaxScore(bit);
	}
	printf("%d", maxscore);
}