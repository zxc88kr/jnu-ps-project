#include <cstdio>
#include <climits>
#include <cmath>

void solve(int x[], int y[], int n)
{
	int minDistSquare = INT_MAX;
	int minCount = 0;

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			int xDist = x[j] - x[i];
			int yDist = y[j] - y[i];
			int distSquare = (xDist * xDist) + (yDist * yDist);

			if (distSquare < minDistSquare)
			{
				minDistSquare = distSquare;
				minCount = 1;
			}
			else if (distSquare == minDistSquare) minCount++;
		}

	printf("%.1lf\n", sqrt(minDistSquare));
	printf("%d\n", minCount);
}

int main()
{
	int n;
	int* x;
	int* y;

	scanf("%d", &n);
	x = new int[n];
	y = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d %d", &x[i], &y[i]);

	solve(x, y, n);

	delete[] x;
	delete[] y;
	return 0;
}