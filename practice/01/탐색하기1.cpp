// 문제해결프로젝트 실습 01 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

/**
 * 배열에서 특정 원소의 인덱스를 찾는 함수
 * @param data 중복 없는 정수 배열 data[0] ~ data[n - 1]
 * @param n    배열의 크기
 * @param m    배열에서 찾고자 하는 원소
 * @return 	   특정 원소가 존재하면 해당 인덱스를, 존재하지 않으면 -1을 반환
 */
int findIndex(int data[], int n, int m)
{
	int index = -1; // 존재하지 않는 경우를 대비하여 인덱스를 -1로 초기화
	for (int i = 0; i < n; i++)
		if (data[i] == m)
		{
			index = i;
			break;
		}
	return index;
}

int main()
{
	int n, m;
	int* data;

	scanf("%d %d", &n, &m);
	data = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	
	int answer = findIndex(data, n, m);
	printf("%d\n", answer);

	delete[] data;
	return 0;
}