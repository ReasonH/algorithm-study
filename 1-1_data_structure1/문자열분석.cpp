#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 48 && s[i] < 58)
				num1++;
			else if (s[i] >= 65 && s[i] < 91)
				num2++;
			else if (s[i] >= 97 && s[i] < 123)
				num3++;
			else if (s[i] == 32)
				num4++;
		}
		cout << num3 << " " << num2 << " " << num1 << " " << num4 << endl;
	}
	return 0;
}