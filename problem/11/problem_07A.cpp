#include <cstdio>

#define MAX_DEPTH 8

bool connected[MAX_DEPTH + 1][MAX_DEPTH + 1] = { false, };
bool visited[MAX_DEPTH + 1] = { false, };

void dfs(int v)
{
	printf("%d\n", v);
	visited[v] = true;

	for (int i = 1; i <= MAX_DEPTH; i++)
		if (connected[v][i] && !visited[i])
			dfs(i);
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		connected[v1][v2] = connected[v2][v1] = true;
	}
	
	dfs(1);
	
	return 0;
}