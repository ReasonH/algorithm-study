#include "pch.h"
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int memo[10] = { 0,1,1,1,1,1,1,1,1,1 }; // 0~9 까지의 갯수, 초기값은 한자리이며 1~9가 한개씩 등장 가능하다
//int cache[10] = { 0 };
//int Ezstair(int input)
//{
//	if (input == 1)
//		return 9;
//	for (int i = 1; i < input; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			if (memo[j] != 0)
//			{
//				if((j+1)!=10)
//					cache[j + 1] = (cache[j + 1] + memo[j]) % 1000000000;
//				if (j != 0)
//				{
//					cache[j - 1] = (cache[j - 1] + memo[j]) % 1000000000;
//					memo[j] -= 1;
//				}
//			}
//		}
//		for (int k = 0; k < 10; k++)
//		{
//			memo[k] = cache[k] % 1000000000;
//			cache[k] = 0;
//		}
//	}
//	int sum = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		sum = (sum + memo[i]) % 1000000000;
//	}
//	return sum;
//}
//int main()
//{
//	int number;
//	cin >> number;
//	cout << Ezstair(number);
//	
//	return 0;
//}