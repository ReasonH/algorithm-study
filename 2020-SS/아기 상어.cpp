#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int map[21][21];
int dist[21][21];
int N;
int directorX[4] = { -1, 1, 0, 0 };
int directorY[4] = { 0, 0, -1, 1 };
struct sharkinfo {
    int lx;
    int ly;
    int size;
    int feed;
};
queue<pair<int, int > > que;
sharkinfo shark;
int sec = 0;

void BFS();
bool eating();
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                shark.lx = i;
                shark.ly = j;
                shark.size = 2;
                shark.feed = 0;
            }
        }
    }
    do {
        BFS();
    } while (eating());
    cout << sec;

    return 0;
}

// 너비우선 탐색으로 물고기들과의 거리를 저장
void BFS() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = 0;
        }
    }

    que.push(make_pair(shark.lx, shark.ly));
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + directorX[i];
            int ny = y + directorY[i];
            if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
                if (map[nx][ny] != 9 && map[nx][ny] <= shark.size && dist[nx][ny] == 0) {
                    dist[nx][ny] = dist[x][y] + 1;
                    que.push(make_pair(nx, ny));
                }
            }
        }
    }
}

// 가장 가까운 애 좌표 찾아서 이동 및 먹기
bool eating() {
    bool flag = false;
    int minimum = 400; // 최단거리
    pair<int, int> locator;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] != 0 && map[i][j] != 9 && dist[i][j] < minimum && dist[i][j] != 0) {
                if (shark.size > map[i][j]) {
                    flag = true;
                    minimum = dist[i][j];
                    locator.first = i;
                    locator.second = j;
                }
            }
        }
    }

    // 먹을게 있다면 움직인다.
    if (flag) {
        map[shark.lx][shark.ly] = 0;
        map[locator.first][locator.second] = 9;
        shark.lx = locator.first;
        shark.ly = locator.second;
        shark.feed++;
        if (shark.feed == shark.size) {
            shark.feed = 0;
            shark.size++;
        }
        sec += minimum;
        return true;
    }
    else {
        return false;
    }
}