#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <ctime>

bool compareCustomer(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

int getMaximumAmount(std::vector<std::pair<int, int>>& customers, int n, int t)
{
    std::priority_queue<int, std::vector<int>, std::less<int>> availableAmount;
    int maximumAmount = 0;
    int idx = 0;

    for (int waiting = t - 1; waiting >= 0; waiting--)
    {
        while (idx < n && customers[idx].first == waiting)
        {
            availableAmount.push(customers[idx].second);
            idx++;
        }

        if (!availableAmount.empty())
        {
            maximumAmount += availableAmount.top();
            availableAmount.pop();
        }
    }
    return maximumAmount;
}

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);

    std::vector<std::pair<int, int>> customers(n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &customers[i].second, &customers[i].first);

    clock_t start = clock();
    
    std::sort(customers.begin(), customers.end(), compareCustomer);

    int maximumAmount = getMaximumAmount(customers, n, t);
    printf("%d\n", maximumAmount);

    clock_t end = clock();

    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}