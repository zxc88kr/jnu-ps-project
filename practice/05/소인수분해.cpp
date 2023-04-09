// 문제해결프로젝트 실습 05 (3)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <vector>

/**
 * 자연수 n을 구성하는 모든 소인수를 벡터 형태로 반환하는 함수
 * @param n 자연수 n
 * @return  자연수 n을 구성하는 모든 소인수를 벡터 형태로 반환
 */
std::vector<int> factorize(int n)
{
    std::vector<int> factors; // 소인수 벡터
    
    for (long long div = 2; div * div <= n; div++) // 2 ~ sqrt(n) 까지의 값을 대상으로 탐색
        while (n % div == 0) // n이 해당 값으로 나누어지는 경우
        {
            factors.push_back((int)div); // 해당 값을 소인수 벡터에 추가
            n /= div; // n을 해당 값으로 나눈 다음, 해당 값으로 더 이상 나누어지지 않을 때까지 반복문 실행
        }
    if (n > 1) factors.push_back(n); // 마지막으로 남은 n이 1보다 클 경우, 이 값을 소인수 벡터에 추가

    return factors;
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int idx = 1; idx <= t; idx++) // 테스트 케이스 번호는 1부터 시작
    {
        int n;
        scanf("%d", &n);

        std::vector<int> factors = factorize(n);

        printf("#%d:\n", idx);
        for (int i = 0; i < factors.size(); i++)
        {
            if (i > 0) printf(" "); // 각 데이터는 공백으로 구분
            printf("%d", factors[i]);
        }
        printf("\n");
    }

    return 0;
}