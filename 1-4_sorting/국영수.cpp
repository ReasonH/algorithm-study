#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Student
{
	int kor = kor;
	int eng = eng;
	int math = math;
	string name = name;
};

bool compare(const Student &A, const Student &B)
{
	if (A.kor > B.kor)
		return true;
	else if (A.kor == B.kor && A.eng != B.eng)
		return (A.eng < B.eng);
	else if (A.kor == B.kor && A.eng == B.eng && A.math != B.math)
		return (A.math > B.math);
	else if (A.kor == B.kor && A.eng == B.eng && A.math == B.math)
		return A.name < B.name;
	else
		return false;
}
int main()
{
	int size;
	scanf_s("%d", &size);
	Student *st = new Student[size];
	for (int i = 0; i < size; i++)
	{
		cin >> st[i].name;
		scanf_s("%d", &st[i].kor);
		scanf_s("%d", &st[i].eng);
		scanf_s("%d", &st[i].math);
	}
	sort(st, st + size, compare);
	for (int i = 0; i < size; i++)
	{
		printf("%s\n", st[i].name.c_str());
	}
	return 0;
}