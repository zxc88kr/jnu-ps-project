#include <cstdio>

bool isPrime(int n)
{
	if (n == 1) return false;
	else if (n == 2) return true;
	else if (n % 2 == 0) return false;

	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;

	return true;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int idx = 0; idx < t; idx++)
	{
		int n;
		scanf("%d", &n);

		bool result = isPrime(n);

		printf("Case #%d\n", idx + 1);
		if (result) printf("YES\n");
		else		printf("NO\n");
	}

	return 0;
}