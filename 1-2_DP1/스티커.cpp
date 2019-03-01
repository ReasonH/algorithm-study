#include <iostream>
#include <algorithm>
using namespace std;
int cache[100001][3] = { 0 };
int arr[2][100001] = { 0 };
void InitArr(int sticknum) {
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= sticknum; j++) {
			int input;
			cin >> input;
			arr[i][j] = input;
		}
	}
}
int Cal_Max(int count) {

	cache[1][0] = 0;
	cache[1][1] = arr[0][1];
	cache[1][2] = arr[1][1];

	for (int i = 2; i <= count; i++) {
		cache[i][0] = max(cache[i - 1][0], max(cache[i - 1][1], cache[i -1][2])); // 해당열 연산없음
		cache[i][1] = max(cache[i - 1][0], cache[i - 1][2]) + arr[0][i]; 
		// 해당열 1행값을 더하는 경우 -> 직전열 2행 값을 선택하는 캐시 or 아무것도 선택하지 않은 캐시 중 최대값을 더한다
		cache[i][2] = max(cache[i - 1][0], cache[i - 1][1]) + arr[1][i];
		// 해당열 2행값을 더하는 경우 -> 직전열 1행 값을 선택하는 캐시 or 아무것도 선택하지 않은 캐시 중 최다값을 더한다
	}
	// 경우의 수를 3가지로 둔다 선택x, 1행 선택, 2행 선택
	return max(cache[count][0], max(cache[count][1], cache[count][2])); // 저장된 캐시 중 최대값 연산
}
int main() {
	int testNum;
	cin >> testNum;
	for (int i = 0; i < testNum; i++) {
		int stickNum;
		cin >> stickNum;
		InitArr(stickNum);
		cout << Cal_Max(stickNum) << endl;
	}
}
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int d[2][100001], a[2][100001]; // DP용 캐시 d와 각 스티커값 a
	d[0][0] = d[1][0] = 0;
	int i, j, n, t; // for문용 i,j 및 연산횟수 t, 열값 n
	cin >> t;
	while (t-- > 0)
	{
		cin >> n;
		for (i = 0; i <= 1; i++)
			for (j = 1; j <= n; j++)
				cin >> a[i][j];
		d[0][1] = a[0][1];
		d[1][1] = a[1][1];
		for (i = 2; i <= n; i++)
		{
			// 1열전 대각선or 2열전 대각선 + 해당열 스티커 값
			d[0][i] = max(d[1][i - 1], d[1][i - 2]) + a[0][i]; // 1열 위부터 시작하는경우 
			d[1][i] = max(d[0][i - 1], d[0][i - 2]) + a[1][i]; // 1열 아래부터 시작하는경우
		}
		cout << max(d[0][n], d[1][n]) << endl;
	}
	return 0;
}