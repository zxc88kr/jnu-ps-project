// 문제해결프로젝트 실습 03 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

/**
 * 주어진 숫자가 소수인지 확인하는 함수
 * @param n 대상이 되는 숫자
 * @return 	주어진 숫자가 소수이면 true, 그렇지 않으면 false를 반환
 */
bool isPrime(int n)
{
	if (n == 1) return false; // 1은 소수가 아님
	else if (n == 2) return true; // 2는 소수가 맞음
	else if (n % 2 == 0) return false; // 2를 제외한 짝수는 소수가 아님

	for (int i = 3; i * i <= n; i += 2) // 3부터 sqrt(n)까지 홀수를 대상으로 탐색
		if (n % i == 0) // 범위 내에 약수가 존재한다면, 그 숫자는 소수가 아님
			return false;

	return true;
}

int main()
{
	int t; // 테스트 케이스 횟수
	scanf("%d", &t);

	for (int idx = 0; idx < t; idx++)
	{
		int n;
		scanf("%d", &n);

		bool result = isPrime(n);

		printf("Case #%d\n", idx + 1); // 실제 번호는 1부터 시작
		if (result) printf("YES\n");
		else		printf("NO\n");
	}

	return 0;
}