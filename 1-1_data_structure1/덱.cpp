#include <iostream>
using namespace std;

class Deq {
private:
	int length;
	int head = 0;
	int tail = 0;
	int maxsize;
	int *arr;
public:
	Deq(int num) {
		maxsize = num;
		arr = new int[maxsize];
	}
	void push_front();
	void push_back();
	void pop_front();
	void pop_back();
	void size();
	void empty();
	void front();
	void back();
};

void Deq::push_front() {
	
}

void Deq::push_back() {

}

void Deq::pop_front() {

}

void Deq::pop_back() {

}

void Deq::size() {

}

void Deq::empty() {

}

void Deq::front() {

}

void Deq::back() {

}

int main()
{
	return 0;
}