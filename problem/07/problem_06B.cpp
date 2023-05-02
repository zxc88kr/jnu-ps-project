#include <cstdio>
#include <vector>
#include <stack>

void solve(std::vector<int>& towers, int n)
{
	std::stack<int> stackHeight;
	std::stack<int> stackIndex;

	for (int i = 0; i < n; i++)
	{
		int targetTowerIndex = 0;

		while (stackHeight.size() > 0 && stackHeight.top() < towers[i])
		{
			stackHeight.pop();
			stackIndex.pop();
		}
		
		if (stackHeight.size() > 0)
			targetTowerIndex = stackIndex.top();

		if (i > 0) printf(" ");
		printf("%d", targetTowerIndex);

		stackHeight.push(towers[i]);
		stackIndex.push(i + 1);
	}
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> towers(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &towers[i]);

	solve(towers, n);

	return 0;
}