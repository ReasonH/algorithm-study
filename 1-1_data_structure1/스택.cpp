#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
	int *arr = new int[5];
	int arrsize = 0;
	int maxsize = 5;
public:
	Stack() {
	}
	void push(int num);
	void pop();
	void size();
	bool empty();
	void top();
};
void Stack::push(int num)
{
	if (arrsize < maxsize) {
		arr[arrsize] = num;
		arrsize++;

		return;
	}
	if (arrsize == maxsize) {
		maxsize += 5;
		int *temp = new int[maxsize];
		for (int i = 0; i < arrsize; i++) {
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = temp;
		arr[arrsize] = num;
		arrsize++;

		return;
	}
}

void Stack::pop()
{
	if (arrsize == 0)
	{
		cout << -1 << endl;
	}
	else {
		cout << arr[arrsize-1] << endl;
		arrsize--;
	}
}

void Stack::size()
{
	cout << arrsize << endl;
}

bool Stack::empty()
{
	if (arrsize == 0) {
		return true;
	}
	else
		return false;
}

void Stack::top()
{
	if (arrsize == 0)
	{
		cout << -1 << endl;
	}
	else {
		cout << arr[arrsize-1] << endl;
	}
}

int main()
{
	Stack st1;
	string command;
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		int num;
		cin >> command;
		if (command == "push")
		{
			cin >> num;
			st1.push(num);
		}
		if (command == "pop")
		{
			st1.pop();
		}
		if (command == "empty")
		{
			if (st1.empty()) {
				cout << 1 << endl;
			}
			else
				cout << 0 << endl;
		}
		if (command == "size")
		{
			st1.size();
		}
		if (command == "top")
		{
			st1.top();
		}
	}
	return 0;
}