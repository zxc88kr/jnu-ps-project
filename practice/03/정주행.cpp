// 문제해결프로젝트 실습 03 (5)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

/**
 * n개의 배열 원소를 연속적인 정수 수열로 표현할 수 있는지 확인하는 함수
 * @param data 중복 없는 정수 배열 data[0] ~ data[n - 1]
 * @param n    배열의 크기
 * @return 	   n개의 배열 원소를 연속적인 정수 수열로 표현할 수 있으면 true, 그렇지 않으면 false를 반환
 */
bool isConsecutive(int data[], int n)
{
	int minData = data[0]; // 최소값을 배열의 첫 번째 원소로 초기화
	int maxData = data[0]; // 최대값을 배열의 첫 번째 원소로 초기화

	for (int i = 1; i < n; i++)
	{
		if (data[i] < minData) minData = data[i];
		else if (data[i] > maxData) maxData = data[i];
	}

	if (maxData - minData == n - 1) return true; // 중복 없는 정수 배열이므로, 연속적인 정수 수열의 (max - min)의 값은 (n - 1)
	return false;
}

int main()
{
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);

	bool result = isConsecutive(data, n);

	if (result) printf("YES\n");
	else		printf("NO\n");

	delete[] data;
	return 0;
}