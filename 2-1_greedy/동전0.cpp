#include <stdio.h>
using namespace std;

int main()
{
	int coin_num, coin_type, aim_cash;
	coin_num = 0;
	scanf_s("%d %d", &coin_type, &aim_cash);
	int *coin = new int[coin_type];
	for (int i = 0; i < coin_type; i++)
	{
		scanf_s("%d", &coin[i]);
	}
	while (aim_cash)
	{
		if (coin[coin_type - 1] <= aim_cash)
		{
			int sub = aim_cash / coin[coin_type - 1];
			aim_cash -= sub * coin[coin_type-1];
			coin_num += sub;
		}
		else
			coin_type--;
	}
	printf("%d", coin_num);
	return 0;
}