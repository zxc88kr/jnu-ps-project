// 문제해결프로젝트 실습 03 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <climits>
#include <cmath>

/**
 * 두 천체 간의 최단 거리와 그 거리만큼 떨어진 천체 쌍의 수를 출력하는 함수
 * @param x 천체의 x좌표 배열 x[0] ~ x[n - 1]
 * @param y 천체의 y좌표 배열 y[0] ~ y[n - 1]
 * @param n 천체의 수
 */
void solve(int x[], int y[], int n)
{
	int minDistSquare = INT_MAX; // 두 천체 간의 최단 거리 제곱을 int 형식의 최대값으로 초기화
	int minCount = 0; // 최단 거리만큼 떨어진 천체 쌍의 수

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			int xDist = x[j] - x[i];
			int yDist = y[j] - y[i];
			int distSquare = (xDist * xDist) + (yDist * yDist); // 두 천체 간의 거리 제곱

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