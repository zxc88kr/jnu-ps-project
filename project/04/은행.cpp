#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

bool comparePair(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);

    std::vector<std::pair<int, int>> people(n);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &people[i].second, &people[i].first);
        
    std::sort(people.begin(), people.end(), comparePair);

    std::priority_queue<int, std::vector<int>, std::less<int>> availAmount;

    int totalAmount = 0;
    int idx = 0;

    for (int i = t - 1; i >= 0; i--)
    {
        while (idx < n && people[idx].first == i)
        {
            availAmount.push(people[idx].second);
            idx++;
        }

        if (!availAmount.empty())
        {
            totalAmount += availAmount.top();
            availAmount.pop();
        }
    }
    printf("%d\n", totalAmount);

    return 0;
}