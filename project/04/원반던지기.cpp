#include <cstdio>
#include <stack>
#include <utility>

int main()
{
    int n;
    scanf("%d", &n);

    long long total = 0;
    std::stack<std::pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        std::pair<int, int> cow;

        scanf("%d", &cow.first);
        cow.second = i;

        while (!st.empty())
        {
            total += (cow.second - st.top().second + 1);

            if (st.top().first < cow.first) st.pop();
            else break;
        }
        st.push(cow);
    }
    printf("%lld\n", total);

    return 0;
}