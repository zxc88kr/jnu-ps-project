// 문제해결프로젝트 실습 02 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

/**
 * 생일이 m월인 도토리들 중 가장 큰 키를 반환하는 함수
 * @param height 도토리들의 키 배열 height[0] ~ height[n - 1]
 * @param month  도토리들의 생일(월) 배열 month[0] ~ month[n - 1]
 * @param n 	 도토리들의 수
 * @param m 	 찾고자 하는 생일(월)
 * @return 		 생일이 m월인 도토리들 중 가장 큰 키를 반환
 */
int getMaximumHeight(int height[], int month[], int n, int m)
{
	int maxHeight = -1; // 찾고자 하는 생일(월)이 존재하지 않는 경우를 대비하여 키를 -1로 초기화
	for (int i = n - 1; i >= 0; i--) // 키가 가장 큰 도토리부터 가장 작은 도토리 순으로 탐색
		if (month[i] == m)
		{
			maxHeight = height[i];
			break;
		}
	return maxHeight;
}

int main()
{
	int n, m;
	int* height;
	int* month;

	scanf("%d", &n);
	height = new int[n];
	month = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &height[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &month[i]);
	scanf("%d", &m);

	int answer = getMaximumHeight(height, month, n, m);
	printf("%d\n", answer);

	delete[] height;
	delete[] month;
	return 0;
}