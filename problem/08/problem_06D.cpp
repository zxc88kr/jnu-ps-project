#include <cstdio>
#include <vector>
#include <queue>

std::vector<int> getDeadPlayers(int n, int m)
{
    std::vector<int> deadPlayers;

    std::queue<int> players;
    for (int i = 0; i < n; i++)
        players.push(i + 1);

    for (int i = 0; i < n; i++)
    {
        int skip = m - 1;
        while (skip > 0)
        {
            int skipPlayer = players.front();
            players.pop();
            players.push(skipPlayer);
            skip--;
        }

        int deadPlayer = players.front();
        players.pop();

        deadPlayers.push_back(deadPlayer);
    }
    return deadPlayers;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int idx = 0; idx < t; idx++)
	{
		int n, m;
		scanf("%d %d", &n, &m);

        std::vector<int> deadPlayers = getDeadPlayers(n, m);

        for (int i = 0; i < deadPlayers.size(); i++)
        {
            if (i > 0) printf(" ");
            printf("%d", deadPlayers[i]);
        }
        printf("\n");
	}

    return 0;
}