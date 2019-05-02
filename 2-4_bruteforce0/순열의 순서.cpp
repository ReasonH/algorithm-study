#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<int> per(20);
int check[21] = { 0 };
long long int number = 1;

long long int Factorial(long long int n);
void prob1(int size);
void prob2(int size);
int main()
{
	int size, cmd;
	scanf_s("%d", &size);
	scanf_s("%d", &cmd);
	switch (cmd)
	{
	case 1:
		prob1(size);
		break;
	case 2:
		prob2(size);
		break;
	default:
		break;
	}

	return 0;
}

void prob1(int size)
{
	scanf_s("%lld", &number); // 찾고싶은 순서 입력
	for (int i = 0; i < size; i++)
	{
		long long int Fact = Factorial(size - i - 1); // 각 항에서 가질 수 있는 팩토리얼 size 20이면, 첫항은 19!
		long long int prefix; 
		prefix = number / Fact; 
		// prefix는 주어진 수에서 팩토리얼 곱이 몇 개 들어가는지 연산
		number = number % Fact; // 나머지로 갱신
		if (number == 0)
		{
			// 나머지가 없는 경우는 팩토리얼로 나누어 떨어진 경우임
			// 이 경우 number와, prefix에 대한 처리를 해줘야한다
			// ex) Fact=4! 일 경우 prefix는 number 1~24에 대해 0이어야함 그러나 저 연산에서는 24에서 1이나옴
			// number도 유사함, 딱 나눠떨어지면 0으로 갱신되는데 그렇게 되면 틀림
			number += Fact; 
			prefix--;
		}
		int count = 0;
		for (int j = 1; j <= size; j++)
		{
			if (check[j] != 1)
				count++;
			if (count == prefix + 1)
			{
				per[i] = j;
				check[j] = 1;
				break;
			}
		}
		printf("%d ", per[i]);
	}
}

void prob2(int size)
{
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &per[i]);
		int count = 0;
		check[per[i]] = 1;
		for (int j = 1; j < per[i]; j++)
		{
			if (check[j] != 1)
				count++;
		}
		number = number + count * Factorial(size - i - 1);
	}
	printf("%lld", number);
}

long long int Factorial(long long int n) {

	long long int result = 1;

	for (int i = 1; i <= n; ++i)
		result *= i;

	return result;
}