#include <stdio.h>
#include <algorithm>
using namespace std;

struct Point
{
	int x = x;
	int y = y;
};

bool compare(const Point &A, const Point &B)
{
	if (A.x < B.x)
		return true;
	else if (A.x == B.x)
		return (A.y < B.y);
	else
		return false;
}
int main()
{
	int size;
	scanf_s("%d", &size);
	Point *pt = new Point[size];
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &pt[i].x);
		scanf_s("%d", &pt[i].y);
	}
	sort(pt, pt + size, compare);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", pt[i].x);
		printf("%d\n", pt[i].y);
	}
	return 0;
}