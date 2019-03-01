#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack<char> st;
	int pipe = 0; // 현재 파이프의 수 (잘리는 대상)
	int piece = 0; // 현재 조각난 파이프 개수
	char before; // 직전 괄호 모양 저장
	
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		st.push(s[i]);
	}

	for (int j = 0; j < s.size(); j++)
	{
		if (st.top() == ')')
		{
			pipe++;
			before = st.top();
			st.pop();
		}
		else
		{
			if (before == ')') {
				pipe--;
				for (int k = 0; k < pipe; k++)
				{
					piece++;
				}
			}
			else {
				piece++;
				pipe--;
			}
			before = st.top();
			st.pop();
		}
	}
	cout << piece;
	return 0;
}