// 문제해결프로젝트 실습 01 (4)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <cmath>

/**
 * 배열의 평균과 가장 가까운 데이터의 인덱스를 찾는 함수
 * @param data 정수 배열 data[0] ~ data[n - 1]
 * @param n    배열의 크기
 * @return 	   배열의 평균과 가장 가까운 데이터의 인덱스를 반환 (여러 개라면 가장 빠른 인덱스)
 */
int findIndex(int data[], int n)
{
	int x = 0; // 데이터의 인덱스를 0으로 초기화
	int sum = 0; // 배열의 총합
	for (int i = 0; i < n; i++)
		sum += data[i];

	for (int i = 0; i < n; i++)
	{
		int dx = abs(n * data[x] - sum); // 이전 원소들과 평균과의 최단 거리
		int di = abs(n * data[i] - sum); // 현재 원소와 평균과의 거리
		if (di < dx) x = i;
	}
	return x + 1; // 실제 번호는 1부터 시작
}

int main()
{
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	
	int answer = findIndex(data, n);
	printf("%d %d\n", answer, data[answer - 1]); // 실제 인덱스는 0부터 시작

	delete[] data;
	return 0;
}