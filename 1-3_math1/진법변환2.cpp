#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string output;
	int input;
	int zin;
	cin >> input >> zin;
	int temp = 0;

	while (input > 0) {
		temp = input % zin;
		input = input / zin;
		if (0 <= temp && temp <= 9)
			output += (temp + '0');
		else
			output += (temp - 10 + 'A');
	}
	reverse(output.begin(), output.end());
	cout << output << endl;
}