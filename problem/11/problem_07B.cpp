#include <cstdio>
#include <queue>

#define MAX_DEPTH 8

bool connected[MAX_DEPTH + 1][MAX_DEPTH + 1] = { false, };
bool visited[MAX_DEPTH + 1] = { false, };

std::queue<int> q;
int num, edge_num;

void bfs(int v)
{
	printf("%d\n", v);
	q.push(v);
	visited[v] = true;

	while (!q.empty())
	{
		v = q.front();
		q.pop();

		for (int i = 1; i <= num; i++)
			if (connected[v][i] && !visited[i])
			{
				printf("%d\n", i);
				q.push(i);
				visited[i] = true;
			}
	}
}

int main()
{
	scanf("%d %d", &num, &edge_num);

	for (int i = 0; i < edge_num; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		connected[v1][v2] = connected[v2][v1] = true;
	}

	bfs(1);

	return 0;
}