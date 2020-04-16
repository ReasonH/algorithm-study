#include <vector>
#include <iostream>
using namespace std;

// 벡터를 행렬화 했을 때 우,좌,상,하는 다음과같음
int directorX[4] = { 0, 0, -1, 1 };
int directorY[4] = { 1, -1 , 0, 0 };
int N, K;

// 하나의 마커 (말) 구조체, 위치와 방향을 갖고있음
struct marker {
	pair<int, int> pos;
	int direction;
};

// 색이 칠해져 있는 지도
vector<vector<int>> map;

// 마커들의 상태를 배열로 관리
vector<marker> markers;

int gameStart(vector<vector<vector<int>>> &markerMap);
int findLevel(int nowX, int nowY, int id, vector<vector<vector<int>>> &markerMap);
void move(int nowX, int nowY, int num, int newX, int newY, int level, vector<vector<vector<int>>> &markerMap, int color);
bool checkEnd(vector<vector<vector<int>>> &markerMap);

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			int mapElem;
			cin >> mapElem;
			row.push_back(mapElem);
		}
		map.push_back(row);
	}
	vector<vector<vector<int>>> markerMap(N, vector<vector<int>>(N, vector<int>(0)));
	for (int i = 0; i < K; i++) {
		int X;
		int Y;
		int direction;
		marker newMarker;
		cin >> X >> Y >> direction;
		newMarker.direction = direction - 1;
		newMarker.pos = make_pair(X - 1, Y - 1);

		markers.push_back(newMarker);
		// 마커맵은 색이 칠해져 있는 map의 크기와 동일하다.
		// 각 인자는 어떤 마커들이 올라가 있는지를 나타낸다
		// 마커(말)은 총 K개이기 때문에 i는 곧 각 마커를 구분하는 번호이다.
		markerMap[X - 1][Y - 1].push_back(i);
	}

	// 게임 시작
	cout << gameStart(markerMap);
	return 0;
}

int gameStart(vector<vector<vector<int>>> &markerMap) {
	int i = 1;
	while (i <= 1000) {
		// 1회당 마커 갯수만큼 내부 루프 진행
		for (int num = 0; num < K; num++) {

			int direction = markers[num].direction;

			int nowX = markers[num].pos.first;
			int nowY = markers[num].pos.second;
			int newX = nowX + directorX[direction];
			int newY = nowY + directorY[direction];
			int level = findLevel(nowX, nowY, num, markerMap);
	
			// 맵을 벗어나는 경우 color = 2 와 동일하게 동작함
			if (newX < 0 || newY >= N ||  newX >= N || newY < 0) {
				move(nowX, nowY, num, newX, newY, level, markerMap, 2);
			} // 나머지는 이동할 위치 color 대로 동작시킨다
			else {
				move(nowX, nowY, num, newX, newY, level, markerMap, map[newX][newY]);
			} 
			// 루프 내에서 지속적으로 게임이 끝나는지 검사한다
			if (checkEnd(markerMap)) {
				return i;
			}
		}
		i++;
	}

	return -1;
}

// 현재 마커맵에서 해당 마커의 높이를 찾는다 (몇번째에 포개어져있는가?)
int findLevel(int nowX, int nowY, int id, vector<vector<vector<int>>> &markerMap) {
	for (int i = 0; i < markerMap[nowX][nowY].size(); i++) {
		if (markerMap[nowX][nowY][i] == id) {
			return i;
		}
	}
}

void move(int nowX, int nowY, int curMarker, int newX, int newY, int level, vector<vector<vector<int>>> &markerMap, int color) {
	int removeCount = 0;
	if (color == 0) { // 0일 경우 일반동작 수행
		for (level; level < markerMap[nowX][nowY].size(); level++) { // 마커맵에서 옮기려는 마커의 level 이상의 마커를 다 옮긴다
			// 마커맵의 새로운 위치에 push_back으로 현재 마커 번호 추가
			int id = markerMap[nowX][nowY][level];
			markerMap[newX][newY].push_back(id);
			// 현재 마커 구조체 위치 변경
			markers[id].pos.first = newX;
			markers[id].pos.second = newY;

			// 마커맵의 이전 위치에서 없앨 마커 갯수 카운트
			removeCount++;
		} 
		// 마커맵의 이전 위치에서 pop_back으로 이전 마커들 삭제
		for (int i = 0; i < removeCount; i++) {
			markerMap[nowX][nowY].pop_back();
		}

	}
	else if (color == 1) { // 0과 동일하지만 마커를 뒤에서부터 가져와 옮김 (역정렬 구현)
		for (int i = markerMap[nowX][nowY].size() - 1; i >= level; i--) {
			int id = markerMap[nowX][nowY][i];
			markerMap[newX][newY].push_back(id);
			markers[id].pos.first = newX;
			markers[id].pos.second = newY;
			removeCount++;
		}
		for (int i = 0; i < removeCount; i++) {
			markerMap[nowX][nowY].pop_back();
		}
	}
	else if (color == 2) { // 2일 경우는 현재 마커의 방향을 전환한다
		if (markers[curMarker].direction == 0 || markers[curMarker].direction == 2)
			markers[curMarker].direction++;
		else {
			markers[curMarker].direction--;
		}
		// 전환한 방향을 이용하여 새로운 위치 계산
		newX = nowX + directorX[markers[curMarker].direction];
		newY = nowY + directorY[markers[curMarker].direction];

		// 위치가 맵에서 벗어나는지 체크
		if (!(newX < 0 || newY >= N || newX >= N || newY < 0)) {
			// 안벗어난다면 변화 위치의 color가 2가 아닌지 체크 (2이면 동작없이 종료)
			if(map[newX][newY] != 2)
				move(nowX, nowY, curMarker, newX, newY, level, markerMap, map[newX][newY]);
		}
	}
}

bool checkEnd(vector<vector<vector<int>>> &markerMap) {
	for (marker elem : markers) {
		if (markerMap[elem.pos.first][elem.pos.second].size() >= 4)
			return true;
	}
	return false;
}