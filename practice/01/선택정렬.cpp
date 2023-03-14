// 문제해결프로젝트 실습 01 (5)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

/**
 * 주어진 범위에서 최소값의 인덱스를 반환하는 함수
 * @param data 	정수 배열 data[0] ~ data[n - 1]
 * @param n 	배열의 크기
 * @param begin 탐색할 배열의 시작 인덱스
 * @param end 	탐색할 배열의 종료 인덱스
 * @return 		data[begin] ~ data[end] 중 최소값의 인덱스를 반환
 */
int getMinIndexInRange(int data[], int n, int begin, int end)
{
	int index = begin;
	for (int i = begin; i <= end; i++)
		if (data[i] < data[index])
			index = i;
	return index;
}

/**
 * 주어진 배열을 선택 정렬하는 함수
 * @param data 정수 배열 data[0] ~ data[n - 1]
 * @param n    배열의 크기
 */
void selectionSort(int data[], int n)
{
	for (int i = 0; i < n; i++)
	{
		// 주어진 범위에서 최소값의 인덱스를 찾음
		int minIndex = getMinIndexInRange(data, n, i, n - 1);
		
		// 최소값의 인덱스와 i번째 인덱스의 값을 서로 교환
		int temp = data[minIndex];
		data[minIndex] = data[i];
		data[i] = temp;
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

	selectionSort(data, n);

	for (int i = 0; i < n; i++)
	{
		if (i > 0) printf(" ");
		printf("%d", data[i]);
	}
	printf("\n");

	delete[] data;
	return 0;
}