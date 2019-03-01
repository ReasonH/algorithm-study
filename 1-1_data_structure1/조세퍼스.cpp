#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> li;
	list<int>::iterator iter;

	int Number, Mumber;
	cin >> Number >> Mumber;

	if (Number == 1)
	{
		cout << "<1>";
		return 0;
	}

	for (int i = 0; i < Number; i++)
	{
		li.push_back(i + 1); // 1~ Number 리스트 생성
	}

	iter = li.begin(); // iter 맨처음으로
	for (int i = 0; i < Number; i++)
	{
		for (int j = 0; j < Mumber - 1; j++)
		{
			iter++;
			if (iter == li.end())
				iter = li.begin();
		}
		if (i == 0)
			cout << '<' << *iter << ',';
		else if (i != Number - 1)
			cout << ' ' << *iter << ',';
		else
			cout << ' ' << *iter;
		iter = li.erase(iter);
		if (iter == li.end())
			iter = li.begin();
	}
	cout << '>';
	return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> q;

	int Num, Mum;
	cin >> Num >> Mum;
	for (int i = 0; i < Num; i++) {
		q.push(i + 1);
	}
	cout << '<';
	while(!q.empty()){
		for (int j = 0; j < Mum - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		if (q.size() != 1)
			cout << ", ";
		q.pop();
	}
	cout << '>';
	return 0;
}