#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
	double num1, num2;
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	string A = a + b;
	num1 = stod(A);
	string B = c + d;
	num2 = stod(B);

	string total = to_string(num1 + num2);
	total.erase(total.size() - 7, total.size());
	cout << total << endl;
	return 0;
}