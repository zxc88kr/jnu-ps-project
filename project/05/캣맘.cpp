#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <ctime>

const int MAX = 16;
const int INF = 1e9;

int N;
int x[MAX + 1], y[MAX + 1];
int dp[MAX + 1][1 << (MAX + 1)];

int getMinimumTimeFeedingCats(int current, int visited)
{
	int& ret = dp[current][visited];

	if (ret != -1) return ret;
	else ret = INF;

	if (visited == (1 << (N + 1)) - 1)
	{
		ret = x[current] + y[current];
		return ret;
	}
	
	for (int next = 1; next <= N; next++)
	{
		if ((visited & (1 << next)) > 0) continue;

		int temp = getMinimumTimeFeedingCats(next, visited | (1 << next)) +
				   std::abs(x[next] - x[current]) + std::abs(y[next] - y[current]);
		ret = std::min(temp, ret);
	}

	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &x[i], &y[i]);

	std::memset(dp, -1, sizeof(dp));

	int minimumTimeFeedingCats = getMinimumTimeFeedingCats(0, 1);
	printf("%d\n", minimumTimeFeedingCats);

	return 0;
}