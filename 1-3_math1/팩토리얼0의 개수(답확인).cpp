#include <iostream>
using namespace std;
// 틀린 답안
//int main()
//{
//	int input;
//	cin >> input;
//	int zerosum = 0;
//	int lastnumber = 1; // 0이아닌 끝자리를 저장하는 변수
//	for (int i = 1; i <= input; i++)// 인풋 팩토리얼 사이즈
//	{
//		lastnumber = lastnumber * i;
//		cout << lastnumber << endl;
//		while (true)
//		{
//			if (lastnumber % 10 == 0) // 10으로 나눠질 경우
//			{
//				lastnumber = lastnumber / 10; // lastnumber는 10으로 나눠준다
//				zerosum++; // 0의 개수 한개 추가
//			}
//			else
//			{
//				lastnumber = lastnumber % 10; // lastnumber가 0이아닌 수가 나올 경우 while 종료
//				break;
//			}
//		}
//	}
//	cout << zerosum << endl;
//	return 0;
//}
int main()
{
	int input;
	int two = 0, five = 0;
	cin >> input;

	for (int i = 2; i <= input; i *= 2)
	{
		two += input / i;
	}
	for (int i = 5; i <= input; i *= 5)
	{
		five += input / i;
	}
	cout << ((two < five) ? two : five);
	return 0;
}
