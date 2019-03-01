#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	list<char> li; // 문자열을 담고 있을 리스트

	string word; // 처음 입력받는 문장
	int cnt = 0; // 명령어 갯수
	cin >> word;
	cin >> cnt;

	char command, ch; // 커맨드와 P명령어에 사용되는 캐릭터
	
	for (int i = 0; i < word.size(); i++)
	{
		li.push_back(word[i]); // 리스트에 문자열 삽입
	}

	list<char>::iterator iter; // 이터레이터 선언
	iter = li.end(); // 이터레이터는 문장의 끝

	for (int i = 0; i < cnt; i++)
	{
		cin >> command;
		switch (command)
		{
		case 'L':
			if (iter == li.begin()) // iter 가 처음이면 동작X
				break;
			else {
				iter--; // 아니면 커서 이동
				break;
			}
		case 'D':
			if (iter == li.end()) // iter 가 끝이면 동작X
				break;
			else {
				iter++; // 아니면 커서 이동
				break;
			}
		case 'B': // 이터레이터 다시 확인
			if (iter == li.begin()) // iter 가 처음이면 동작X
				break;
			else {
				iter--;
				iter = li.erase(iter); // iter가 가르키는 것 삭제
				break;
			}
		case 'P':
			cin >> ch;
			li.insert(iter, ch);
			break;
		default:
			break;
		}
	}

	for (iter = li.begin(); iter != li.end(); iter++)
	{
		cout << *iter;
	}
	return 0;
}