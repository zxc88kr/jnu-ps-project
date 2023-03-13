#include <cstdio>

int getRangeSumFromOne(int i)
{
	int answer = 0;
	for (int j = 1; j <= i; j++)
		answer += j;
	return answer;
}

long long getAnswer(int n)
{
	long answer = 0;
	for (int i = 1; i <= n; i++)
	{
		int rangeSum = getRangeSumFromOne(i);
		answer += rangeSum;
	}
	return answer;
}

int main()
{
	int n;
	scanf("%d", &n);

	long long answer = getAnswer(n);
	printf("%lld\n", answer);

	return 0;
}