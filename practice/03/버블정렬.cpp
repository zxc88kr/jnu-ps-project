// 문제해결프로젝트 실습 03 (3)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

/**
 * 주어진 배열을 버블 정렬하는 함수
 * @param data 정수 배열 data[0] ~ data[n - 1]
 * @param n    배열의 크기
 */
void bubbleSort(int data[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int negativeCount = 0; // 배열 원소 간의 자리 이동 횟수
		for (int j = 0; j < n - 1 - i; j++) // 탐색할 인덱스의 최대 범위를 1씩 감소
			if (data[j] > data[j + 1]) // 현재 원소의 값이 다음 원소의 값보다 큰 경우
			{
				// 현재 원소의 값과 다음 원소의 값을 서로 교환
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
				
				negativeCount++;
			}
		if (negativeCount == 0) break; // 배열 원소 간의 자리 이동이 없으면 정렬이 완료된 것
	}
}

int main()
{
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);

	bubbleSort(data, n);

	for (int i = 0; i < n; i++)
	{
		if (i > 0) printf(" "); // 각 데이터는 공백으로 구분
		printf("%d", data[i]);
	}
	printf("\n");

	delete[] data;
	return 0;
}