#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<char> st;
	int cnt;
	string word;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		cin >> word;
		int num = 0;
		for (int j = 0; j < word.size(); j++)
		{
			st.push(word[j]);
		}
		for (int k = 0; k < word.size(); k++)
		{
			if (st.top() == ')') {
				num++;
				st.pop();
			}
			else if (st.top() == '(')
			{
				num--;
				if (num < 0)
					break;
				st.pop();
			}
		}
		if (num == 0)
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}