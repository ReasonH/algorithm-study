#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<float, int> a, pair<float, int> b);
vector<int> solution(int N, vector<int> stages);

int main() {
    vector<int> answer = solution(4, { 4,4,4,4,4});
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }
    return 0;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int* count = new int[N + 1]; // 도달한 사람
    int* countUnfinish = new int[N + 1]; // 도달하고 클리어 못한사람
    fill(count, count + N + 1, 0);
    fill(countUnfinish, countUnfinish + N + 1, 0);
    
    vector<pair<float, int>> failRateStages;

    sort(stages.begin(), stages.end());

    int before = 0;
    int size = stages.size();
    for (int i = 0; i < size; i++) {
        if (stages[i] == N+1) {
            break;
        }
        else if (before != stages[i]) {
            count[stages[i]] = size - i;
            before = stages[i];
            countUnfinish[before] += 1;
        }
        else if (before == stages[i]) {
            countUnfinish[before] += 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (count[i] == 0) {
            failRateStages.push_back(make_pair(0, i));
            cout << 0 << ' ' << i << endl;
        }
        else {
            float failRate = (float)countUnfinish[i] / count[i];
            failRateStages.push_back(make_pair(failRate, i));
            cout << failRate << ' ' << i << endl;
        }
    }
    sort(failRateStages.begin(), failRateStages.end(), compare);


    for (int i = 0; i < N; i++) {
        answer.push_back(failRateStages[i].second);
    }

    return answer;
}
bool compare(pair<float, int> a, pair<float, int> b) {
    if (a.first > b.first) {
        return true;
    }
    else if (a.first < b.first) {
        return false;
    }
    else {
        if (a.second < b.second) {
            return true;
        }
        else {
            return false;
        }
    }
}