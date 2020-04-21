#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r;
int c;
int k;
int row = 3;
int col = 3;
vector<pair<int, int>> realPair; // 히스토그램 중 유효 pair 저장
int map[101][101]; // 정적 초기화 0으로 되어 있음
int histogram[101]; // 히스토그램 파악

int calculate();
void calculateR();
void calculateC();

int main() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> map[i][j];
		}
	}
	cout << calculate();
	return 0;
}

int calculate() {
	int time = 0;
	do {
		if (row >= r && col >= c) { // 검증
			if (map[r][c] == k) {
				return time;
			}
		}
		time++;
		if (row >= col) {
			calculateR();
		}
		else {
			calculateC();
		}
	} while (time <= 100);
	return -1;
}

// R 계산
void calculateR() {
	int maximum = 0;
	for (int i = 1; i <= row; i++) {
		realPair.clear(); // realPair 초기화
		fill(histogram, histogram + 101, 0); // histogram 초기화

		for (int j = 1; j <= col; j++) {
			histogram[map[i][j]]++; // 인덱스 = 해당 수, 내용 = 등장 횟수
			// ** 중요! map이 0인 경우는 histogram에 저장은 되지만 사용되지 않음
			map[i][j] = 0; // 저장 후 해당 자리 비워놓음
		}
		for (int j = 1; j <= 100; j++) {
			if (histogram[j] != 0) { // 히스토그램 0이 아닌 경우 (1회라도 수가 등장)
				realPair.push_back(make_pair(histogram[j], j)); // realPair에 담는다
			}
		}
		// realPair는 인덱스 내용, 인덱스 순으로 담겨있음
		// sort 시 많이 등장한 순으로 정렬, 동일한 경우 인덱스 작은 순 정렬
		sort(realPair.begin(), realPair.end());

		// 몇 종류의 숫자(인덱스)가 있는가?
		int pairSize = realPair.size();
		int localMax = 0; // 열의 길이 측정
		// 인덱스, 인덱스 갯수 순으로 map에 다시 저장
		for (int j = 0; j < pairSize; j++) {
			map[i][++localMax] = realPair[j].second;
			map[i][++localMax] = realPair[j].first;
		}
		maximum = max(localMax, maximum); // 각 행을 계산하며 가장 긴 열을 뽑는다.
	}
	col = maximum; // 최대열 저장
}

void calculateC() {
	int maximum = 0;
	for (int i = 1; i <= col; i++) {
		realPair.clear();
		fill(histogram, histogram + 101, 0);
		for (int j = 1; j <= row; j++) {
			histogram[map[j][i]]++;
			map[j][i] = 0;
		}
		for (int j = 1; j <= 100; j++) {
			if (histogram[j] != 0) {
				realPair.push_back(make_pair(histogram[j], j));
			}
		}
		sort(realPair.begin(), realPair.end());

		int pairSize = realPair.size();
		int localMax = 0;
		for (int j = 0; j < pairSize; j++) {
			map[++localMax][i] = realPair[j].second;
			map[++localMax][i] = realPair[j].first;
		}
		maximum = max(localMax, maximum);
	}
	row = maximum;
}