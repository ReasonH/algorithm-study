#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(string p);
int getDivideIndex(string p);
bool isRight(string u);
string newRange(string s);

int main() {
    solution(")(");
    return 0;
}

string solution(string p) {
    string answer = "";
    answer = newRange(p);
    cout << answer;
    return answer;
}

string newRange(string p) {
    if (p == "") {
        return "";
    }
    string u = p.substr(0, getDivideIndex(p));
    string v = p.substr(getDivideIndex(p), p.size());
    cout << u << ' ' << v << endl;
    if (isRight(u)) {
        return u + newRange(v);
    }
    else {
        string s = "(" + newRange(v) + ")";
        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(') {
                s += ')';
            }
            else {
                s += '(';
            }
        }
        return s;
    }
}

int getDivideIndex(string p) {
    int left = 0;
    int right = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            left++;
        }
        else {
            right++;
        }
        if (left == right) {
            return i + 1;
        }
    }
    return 0;
}

bool isRight(string u) {
    stack<char> stk;
    for (int i = 0; i < u.size(); i++) {
        if (stk.size() == 0) {
            if (u[i] == ')') {
                return false;
            }
            else {
                stk.push(u[i]);
            }
        }
        else if (stk.top() == '(' && u[i] == ')') {
            stk.pop();
        }
        else {
            stk.push(u[i]);
        }
    }
    if (stk.size() == 0) {
        return true;
    }
    else {
        return false;
    }
}