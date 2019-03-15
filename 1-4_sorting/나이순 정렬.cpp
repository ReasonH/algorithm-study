#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Member
{
	int age = age;
	string name = name;
	int order = order;
};

bool compare(const Member &A, const Member &B)
{
	if (A.age < B.age)
		return true;
	else if (A.age == B.age)
		return (A.order < B.order);
	else
		return false;
}
int main()
{
	int size;
	scanf_s("%d", &size);
	Member *mb = new Member[size];
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &mb[i].age);
		getline(cin, mb[i].name);
		mb[i].order = i;
	}
	sort(mb, mb + size, compare);
	for (int i = 0; i < size; i++)
	{
		printf("%d", mb[i].age);
		printf("%s\n", mb[i].name.c_str());
	}
	return 0;
}