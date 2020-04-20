#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N = 0;
int M = 0;

// 연구소 상태
int lab[51][51];
// 감염 상태
int infection[51][51];
// 바이러스 위치
vector<pair<int, int> > virus;
// for BFS
queue<pair<int, int> > que;
int least = 100000;
bool flag = false;
// 상하좌우
int directorX[4] = { -1, 1, 0, 0 };
int directorY[4] = { 0, 0, -1, 1 };

void BFS(int space);
void infectionInit();
int main() {
    int space = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            }
            else if (lab[i][j] == 0) {
                space++;
            }
        }
    }

    int virusSpace = virus.size();
    // 바이러스 활성 위치 선택을 위한 순열: visrusSize 중 M개 선택
    vector<int> selection;
    for (int i = 1; i <= virusSpace - M; i++) {
        selection.push_back(0);
    }
    for (int i = 1; i <= M; i++) {
        selection.push_back(1);
    }

    // 모든 조합에대해 수행
    do {
        infectionInit(); // 감염지도 초기화
        for (int i = 0; i < selection.size(); i++) {
            if (selection[i] == 1) {
                que.push(make_pair(virus[i].first, virus[i].second));
                infection[virus[i].first][ virus[i].second] = -3;
            }
        }
        BFS(space);
    } while (next_permutation(selection.begin(), selection.end()));

    if (flag) {
        cout << least;
    }
    else {
        cout << -1;
    }

    return 0;
}

void infectionInit() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (lab[i][j] == 0) { // 빈공간 
                infection[i][j] = 0;
            }
            else if (lab[i][j] == 1){ // 벽 위치는 -1
                infection[i][j] = -1;
            }
            else { // 바이러스 위치
                infection[i][j] = -2;
            }
        }
    }
}

void BFS(int space) {
    int maximum = 0;
    while (!que.empty()) {
        pair<int, int> location = que.front();
        int X = location.first;
        int Y = location.second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nX = X + directorX[i];
            int nY = Y + directorY[i];
            if (space <= 0) {
                break;
            }
            if (nX >= 1 && nX <= N && nY >= 1 && nY <= N) {
                // 새로운 위치가 빈 공간 or 바이러스 위치인 경우 진행
                if (infection[nX][nY] == 0 || infection[nX][nY] == -2) {
                    if (infection[nX][nY] == 0) {
                        space--;
                    }
                    // 기존 위치가 바이러스 원점인 경우
                    if (infection[X][Y] == -3) {
                        infection[nX][nY] = 1; // 감염위치의 시간은 1로 설정
                    }
                    else { // 기존 위치가 바이러스 감염지역인 경우
                        infection[nX][nY] = infection[X][Y] + 1;
                    }
                    que.push(make_pair(nX, nY));
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            maximum = max(infection[i][j], maximum);
            if (infection[i][j] == 0) { // 감염시키지 못한칸이 있으면 실패로 바로 종료
                return;
            }
        }
    }
    flag = true;
    least = min(least, maximum);
}