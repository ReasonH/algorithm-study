#include <stdio.h>
#include <algorithm>
using namespace std;

struct number
{
	int num = num;
	int index = index;
};
bool compare(const number &A, const number &B)
{
	if (A.num < B.num)
		return true;
	else
		return false;
}
int main()
{
	int size;
	scanf_s("%d", &size);
	number *arr = new number[size+1];
	for (int i = 1; i <= size; i++)
	{
		scanf_s("%d", &arr[i].num);
		arr[i].index = i;
	}
	stable_sort(arr + 1, arr + size + 1, compare);
	int max = 0;
	for (int i = 1; i <= size; i++)
	{
		if (arr[i].index - i > max)
			max = arr[i].index -i;
	}
	printf("%d", ++max);

	return 0;
}