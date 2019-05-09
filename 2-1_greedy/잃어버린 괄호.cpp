//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	string expression;
//	vector<string> num_vec;
//	cin >> expression;
//	int s_string = 0;
//	for (int i = 0; i < expression.size(); i++)
//	{
//		if (expression[i] == '-' || expression[i] == '+')
//		{
//			string num;
//			for (int j = s_string; j < i; j++)
//			{
//				num.push_back(expression[j]);
//			}
//			s_string = i;
//			num_vec.push_back(num);
//		}
//		else if (i == expression.size() - 1)
//		{
//			string num;
//			for (int j = s_string; j <= i; j++)
//			{
//				num.push_back(expression[j]);
//			}
//			num_vec.push_back(num);
//		}
//	}
//	int total = 0;
//	bool check = false;
//	for (int i = 0; i < num_vec.size(); i++)
//	{
//		if (atoi(num_vec[i].c_str()) < 0)
//			check = true;
//		if (check)
//		{
//			if (atoi(num_vec[i].c_str()) < 0)
//				total += atoi(num_vec[i].c_str());
//			else
//				total -= atoi(num_vec[i].c_str());
//		}
//		else
//			total += atoi(num_vec[i].c_str());
//	}
//	printf("%d", total);
//	return 0;
//}