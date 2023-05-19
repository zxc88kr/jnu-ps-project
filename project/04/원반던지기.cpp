#include <cstdio>
#include <vector>
#include <utility>
#include <stack>
#include <ctime>

long long getSumFrisbeeDistance(std::vector<std::pair<int, int>>& cows, int n)
{
    std::stack<std::pair<int, int>> stackCow;
    long long sumFrisbeeDistance = 0;

    for (int i = 0; i < n; i++)
    {
        while (!stackCow.empty())
        {
            sumFrisbeeDistance += (cows[i].second - stackCow.top().second + 1);

            if (stackCow.top().first < cows[i].first) stackCow.pop();
            else break;
        }
        stackCow.push(cows[i]);
    }
    return sumFrisbeeDistance;
}

int main()
{
    int n;
    scanf("%d", &n);

    std::vector<std::pair<int, int>> cows(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cows[i].first);
        cows[i].second = i + 1;
    }

    clock_t start = clock();

    long long sumFrisbeeDistance = getSumFrisbeeDistance(cows, n);
    printf("%lld\n", sumFrisbeeDistance);

    clock_t end = clock();

    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}