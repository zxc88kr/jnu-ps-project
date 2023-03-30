#include <cstdio>
#include <vector>

const int MAX_SIZE = 1000000;
std::vector<int> FIBONACCI_TABLE;

std::vector<int> makeFibonacciTable(int n)
{
    const int MOD = 100000000;

    std::vector<int> answer(n + 1);
    answer[1] = 0;
    answer[2] = 1;

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