#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
	int maxsize;
	int length = 0;
	int *arr;
	int tail = 0;
	int head = 0;
public:
	Queue(int numb) {
		maxsize = numb;
		arr = new int[maxsize];
	}
	void push(int num);
	int pop();
	int size();
	int empty();
	int front();
	int back();
};
void Queue::push(int num)
{
	arr[tail] = num;
	tail++;
	length++;
	return;
}
int Queue::pop()
{
	if (length == 0)
	{
		return -1;
	}
	else {
		int temp = arr[head];
		head++;
		length--;
		return temp;
	}
}
int Queue::size() {
	return length;
}
int Queue::empty() {
	if (length == 0)
		return 1;
	else
		return 0;
}
int Queue::front() {
	if (length == 0)
		return -1;
	else {
		return arr[head];
	}
}

int Queue::back() {
	if (length == 0)
		return -1;
	else {
		return arr[tail-1];
	}
}

int main()
{
	int cnt;
	int num;
	string command;
	cin >> cnt;
	Queue q(cnt);
	for (int i = 0; i < cnt; i++)
	{
		cin >> command;
		if (command == "push")
		{
			cin >> num;
			q.push(num);
		}
		else if (command == "pop")
		{
			cout << q.pop() << endl;
		}
		else if (command == "empty")
		{
			cout << q.empty() << endl;
		}
		else if (command == "size")
		{
			cout << q.size() << endl;
		}
		else if (command == "front")
		{
			cout << q.front() << endl;
		}
		else if (command == "back")
		{
			cout << q.back() << endl;
		}
	}
	return 0;
}