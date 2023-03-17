// 문제해결프로젝트 실습 02 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

/**
 * 키가 오름차순으로 정렬되어 있는지 확인하는 함수
 * @param height 학생들의 키 배열 height[0] ~ height[n - 1]
 * @param n 	 학생들의 수
 * @return 		 키가 오름차순으로 정렬되어 있으면 true, 그렇지 않으면 false를 반환
 */
bool isOrdered(int height[], int n)
{
	bool result = true; // 예외가 발생하지 않는 한, 키가 오름차순으로 정렬되어 있다고 가정하고 결과를 초기화
	for (int i = 0; i < n - 1; i++)
		if (height[i] > height[i + 1])
		{
			result = false;
			break;
		}
	return result;
}

int main()
{
	int n;
	int* height;

	scanf("%d", &n);
	height = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &height[i]);

	bool result = isOrdered(height, n);
	if (result) printf("YES\n");
	else		printf("NO\n");

	delete[] height;
	return 0;
}