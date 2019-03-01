#include "pch.h"
//#include <algorithm>
//#include <iostream>
//using namespace std;
//
//int numseq[1001] = { 0 };
//int dp[1001] = { 0 };
//void partseq(int input)
//{
//	int length = 1;
//	dp[1] = 1;
//	for (int i = 2; i <= input; i++)
//	{
//		for (int j = i - 1; j > 0; j--)
//		{
//			if (numseq[j] < numseq[i] && dp[j] >= dp[i])
//			{
//				dp[i] = dp[j] + 1;
//				length = max(dp[i], length);
//			}
//		}
//		if (dp[i] == 0)
//		{
//			dp[i] = 1; 
//		}
//	}
//	cout << length;
//}
//
//int main()
//{
//	int num;
//	cin >> num;
//	for (int i = 1; i <= num; i++)
//	{
//		cin >> numseq[i];
//	}
//	partseq(num);
//	return 0;
//}