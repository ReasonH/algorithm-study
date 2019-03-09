#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int start, end;
	bool isPrime;
	scanf("%d %d", &start, &end);
	for (int i = start; i <= end; i++) {
		isPrime = true;
		if (i == 1)
			isPrime = false;

		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			printf("%d\n", i);
	}
	return 0;
}