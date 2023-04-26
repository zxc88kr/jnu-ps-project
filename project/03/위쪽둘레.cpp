#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> shortLength(n);
	std::vector<int> longLength(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &shortLength[i], &longLength[i]);

	std::vector<int> lastStandPath(n);
	std::vector<int> lastLiePath(n);
	lastStandPath[0] = shortLength[0];
	lastLiePath[0] = longLength[0];

	for (int i = 1; i < n; i++)
	{
		int previousShort = shortLength[i - 1];
		int previousLong = longLength[i - 1];
		int currentShort = shortLength[i];
		int currentLong = longLength[i];

		lastStandPath[i] = std::max(lastStandPath[i - 1] + std::abs(currentLong - previousLong) + currentShort, // 서있고 서있다
									lastLiePath[i - 1] + std::abs(currentLong - previousShort) + currentShort); // 누워있고 서있다
		lastLiePath[i] = std::max(lastStandPath[i - 1] + std::abs(currentShort - previousLong) + currentLong, // 서있고 누워있다
								  lastLiePath[i - 1] + std::abs(currentShort - previousShort) + currentLong); // 누워있고 누워있다
	}
	printf("%d\n", std::max(lastStandPath[n - 1], lastLiePath[n - 1]));

	return 0;
}