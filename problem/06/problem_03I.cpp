#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> getPossibleTargets(int n, int m, std::vector<int>& cards, std::vector<int>& targets)
{
    std::vector<int> possibleTargets;

    std::sort(cards.begin(), cards.end());

    for (int idx = 0; idx < m; idx++)
    {
        int target = targets[idx];
        bool possible = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                int x = cards[i];
                int y = cards[j];
                int z = target - x - y;

                if (std::binary_search(cards.begin(), cards.end(), z))
                {
                    possible = true;
                    break;
                }
            }
            if (possible) break;
        }
        if (possible) possibleTargets.push_back(target);
    }
    std::sort(possibleTargets.begin(), possibleTargets.end());

    return possibleTargets;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<int> cards(n);
    std::vector<int> targets(m);

    for (int i = 0; i < n; i++)
        scanf("%d", &cards[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &targets[i]);

    std::vector<int> answers = getPossibleTargets(n, m, cards, targets);

    if (answers.size() > 0)
    {
        for (int i = 0; i < answers.size(); i++)
        {
            if (i > 0) printf(" ");
            printf("%d", answers[i]);
        }
        printf("\n");
    }
    else printf("NO\n");

    return 0;
}