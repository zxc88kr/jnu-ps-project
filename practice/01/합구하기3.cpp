// 문제해결프로젝트 실습 01 (6)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

/**
 * (1 + ... + n) 의 결과를 반환하는 함수
 * @param i 반복문 종료 인덱스
 * @return 	(1 + ... + i) 의 결과를 반환
 */
int getRangeSumFromOne(int i)
{
	int answer = 0;
	for (int j = 1; j <= i; j++)
		answer += j;
	return answer;
}

/**
 * (1) + (1 + 2) + (1 + ... + n) 의 결과를 반환하는 함수
 * @param n 반복문 종료 인덱스
 * @return 	(1) + (1 + 2) + (1 + ... + n) 의 결과를 반환
 */
long long getAnswer(int n)
{
	long answer = 0;
	for (int i = 1; i <= n; i++)
	{
		int rangeSum = getRangeSumFromOne(i);
		answer += rangeSum;
	}
	return answer;
}

int main()
{
	int n;
	scanf("%d", &n);

	long long answer = getAnswer(n);
	printf("%lld\n", answer);

	return 0;
}