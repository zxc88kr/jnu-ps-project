// 문제해결프로젝트 실습 04 (4)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <vector>

const int MAX_SIZE = 1000000; // 수열의 최대 크기 1 ~ 1000000
std::vector<int> FIBONACCI_TABLE; // 각 항의 값을 저장하는 피보나치 수열 벡터

/**
 * 피보나치 수열의 1 ~ n 번째 항의 값을 저장하는 테이블을 생성하는 함수
 * @param n 구하고자 하는 수열의 마지막 항
 * @return  피보나치 수열의 1 ~ n 번째 항의 값을 저장하는 테이블을 반환
 */
std::vector<int> makeFibonacciTable(int n)
{
    const int MOD = 100000000; // 나머지 연산을 위한 제수 (마지막 8자리 숫자를 저장)

    std::vector<int> answer(n + 1); // 실제 번호는 1부터 시작하므로 사이즈를 1 증가 table[0] ~ table[100000]
    answer[1] = 0; // 첫 번째 항의 값은 0
    answer[2] = 1; // 두 번째 항의 값은 1

    for (int i = 3; i <= n; i++)
        answer[i] = (answer[i - 1] + answer[i - 2]) % MOD;

    return answer;
}

int main()
{
    FIBONACCI_TABLE = makeFibonacciTable(MAX_SIZE);

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        printf("%d\n", FIBONACCI_TABLE[n]);
    }

    FIBONACCI_TABLE.clear();
    return 0;
}