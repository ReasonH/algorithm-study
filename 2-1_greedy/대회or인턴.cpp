#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int female, male, intern, team;
	team = 0;
	scanf_s("%d %d %d", &female, &male, &intern);
	while (female - 2 >= 0 && male - 1 >= 0)
	{
		female -= 2;
		male -= 1;
		team++;
	}
	intern = intern - female - male;
	int loop = intern / 3;
	for (int i = 0; i < loop; i++)
	{
		intern -= 3;
		team--;
	}
	if (intern > 0)
		team--;
	printf("%d", team);
	return 0;
}