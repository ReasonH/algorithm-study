#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
vector<string> combination;
int column = 0;

//string 비교함수 길이로 먼저 정렬을하고 같으면 큰순서대로 정렬한다
bool compare(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    return a < b;
}

//모든 조합을 만드는 함수
void makeComb() {
    for (int i = 0; i < column; i++) {
        vector<int> selector;
        for (int j = 0; j < i; j++) {
            selector.push_back(0);
        }
        for (int j = 0; j < column - i; j++) {
            selector.push_back(1);
        }
        do {
            string temp = "";
            for (int j = 0; j < column; j++) {
                if (selector[j] == 1) {
                    temp += to_string(j);
                }
            }
            combination.push_back(temp);
        } while (next_permutation(selector.begin(), selector.end()));
    }
}

//조합에따른 후보키 가능 여부 확인
bool subset(vector<vector<string>> relation, string combination) {
    set<string> keySet;
    for (int i = 0; i < relation.size(); i++) {
        string key = "";
        for (int j = 0; j < combination.length(); j++) {
            int colNumber = combination[j] - '0';
            key += relation[i][colNumber];
        }
        keySet.insert(key);
    }
    if (keySet.size() != relation.size()) {
        return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    column = relation[0].size();
    makeComb();
    sort(combination.begin(), combination.end(), compare);
    
    // 조합수만큼 반복
    for (int i = 0; i < combination.size(); i++) {
        if (subset(relation, combination[i])) {
            string temp = combination[i];
            //후보키조합이 겹치는 조합 삭제
            for (int j = combination.size() - 1; j >= i; j--) { // j~i까지인건 본인까지 삭제하기 위함
                bool check = true;
                for (auto t : temp) { // 키에 속한 attribute가 하나라도 속하지 않으면 check false 
                    if (combination[j].find(t) == string::npos) {
                        check = false;
                        break;
                    }
                }
                if (check) { // 키에 속한 모든 attribute가 발견된 경우 조합에서 삭제
                    combination.erase(combination.begin() + j);
                }
            }
            i--;
            answer++;
        }
    }
    return answer;
}