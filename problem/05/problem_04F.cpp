#include <cstdio>
#include <vector>

const int MAX_SIZE = 1000000;
std::vector<bool> PRIME_TABLE;

std::vector<bool> makePrimeTable(int n)
{
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int num = 2; num <= n; num++)
    {
        if (!isPrime[num]) continue;

        for (long long mul = (long long)num * num; mul <= n; mul += num)
            isPrime[(int)mul] = false;
    }
    return isPrime;
}

int main()
{
    PRIME_TABLE = makePrimeTable(MAX_SIZE);

    int t;
    scanf("%d", &t);

    for (int idx = 1; idx <= t; idx++)
    {
        int l, r;
        scanf("%d %d", &l, &r);

        int primeNumberCount = 0;
        for (int num = l; num <= r; num++)
            if (PRIME_TABLE[num])
                primeNumberCount++;

        printf("Case #%d:\n", idx);
        printf("%d\n", primeNumberCount);
    }

    PRIME_TABLE.clear();
    return 0;
}