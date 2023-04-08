#include <cstdio>
#include <vector>

std::vector<int> factorize(int n)
{
    std::vector<int> factors;
    
    for (long long div = 2; div * div <= n; div++)
        while (n % div == 0)
        {
            factors.push_back((int)div);
            n /= div;
        }
    if (n > 1) factors.push_back(n);

    return factors;
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int idx = 1; idx <= t; idx++)
    {
        int n;
        scanf("%d", &n);

        std::vector<int> factors = factorize(n);

        printf("#%d:\n", idx);
        for (int i = 0; i < factors.size(); i++)
        {
            if (i > 0) printf(" ");
            printf("%d", factors[i]);
        }
        printf("\n");
    }

    return 0;
}