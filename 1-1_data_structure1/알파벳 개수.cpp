#include <iostream>
#include <string>
using namespace std;
int main() {
	int arr[26] = { 0 };
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		arr[s[i]-97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}