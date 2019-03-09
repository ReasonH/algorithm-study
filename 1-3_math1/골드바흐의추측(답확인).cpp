#include <cstdio>
#include <algorithm>

#define SIZE 1000000

using namespace std;

int isNotPrime[SIZE];

void eratosthenes() {
	for (int i = 2; i*i < SIZE; i++)
		if (!isNotPrime[i])
			for (int j = i * i; j < SIZE; j += i)
				isNotPrime[j] = 1;
	isNotPrime[1] = 1;
}

int main()
{
	eratosthenes();
	int n;
	while (1)
	{
		scanf_s("%d", &n);
		if (n == 0)
			break;

		bool chk = false;
		for (int i = 3; i <= n; i += 2)
			if (!isNotPrime[i] && !isNotPrime[n - i])
			{
				printf("%d = %d + %d\n", n, i, n - i);
				chk = true;
				break;
			}
		if (!chk)
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}