// 문제해결프로젝트 실습 02 (3)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

/**
 * 배열에서 중복을 제외한 종류의 수를 반환하는 함수
 * @param data 정수 배열 data[0] ~ data[n - 1]
 * @param n    정수 배열의 크기
 * @return 	   배열에서 중복을 제외한 종류의 수를 반환
 */
int getElementTypeCount(int data[], int n)
{
	int typeCount = 0; // 종류의 수를 0으로 초기화
	for (int i = 0; i < n; i++)
		if (i == 0 || data[i - 1] != data[i]) // 첫 번째 원소는 비교할 이전 대상이 없으므로, 비교 과정을 생략
			typeCount++;
	return typeCount;
}

int main()
{
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);

	int answer = getElementTypeCount(data, n);
	printf("%d\n", answer);

	delete[] data;
	return 0;
}