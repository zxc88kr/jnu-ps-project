// 문제해결프로젝트 실습 05 (4)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <vector>

const int MAX_SIZE = 1000000; // 테이블의 최대 크기 1 ~ 1000000
std::vector<bool> PRIME_TABLE; // 소수 여부를 저장하고 있는 소수 테이블 벡터

/**
 * 1 ~ n 까지의 값을 대상으로 소수를 판별하는 테이블을 반환하는 함수
 * @param n 테이블의 마지막 번호
 * @return  1 ~ n 까지의 값을 대상으로 소수를 판별하는 테이블을 반환
 */
std::vector<bool> makePrimeTable(int n)
{
    std::vector<bool> isPrime(n + 1, true); // 초기에는 테이블의 모든 값이 소수라고 가정
    isPrime[0] = false; // 0은 소수가 아님
    isPrime[1] = false; // 1은 소수가 아님

    for (int num = 2; num <= n; num++) // 2 ~ n 까지의 값을 대상으로 에라토스테네스의 체 적용
    {
        if (!isPrime[num]) continue; // 해당 값이 소수가 아닐 경우 스킵

        // num * num ~ n 까지 num의 배수를 대상으로 탐색
        // 예시 (num = 3, n = 20)
        // 9, 12, 15, 18 을 대상으로 탐색
        for (long long mul = (long long)num * num; mul <= n; mul += num)
            isPrime[(int)mul] = false; // 해당 값은 소수가 아니라고 체크
    }
    return isPrime;
}

int main()
{
    PRIME_TABLE = makePrimeTable(MAX_SIZE); // 프라임 테이블 생성

    int t;
    scanf("%d", &t);

    for (int idx = 1; idx <= t; idx++) // 테스트 케이스 번호는 1부터 시작
    {
        int l, r;
        scanf("%d %d", &l, &r);

        int primeNumberCount = 0; // 소수의 개수를 0으로 초기화
        for (int num = l; num <= r; num++) // l부터 r까지의 값을 대상으로 탐색
            if (PRIME_TABLE[num]) // 해당 값이 소수인 경우
                primeNumberCount++; // 소수의 개수를 1씩 증가

        printf("Case #%d:\n", idx);
        printf("%d\n", primeNumberCount);
    }

    PRIME_TABLE.clear();
    return 0;
}