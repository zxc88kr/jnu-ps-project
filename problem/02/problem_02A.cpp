#include <cstdio>

int getMaximumHeight(int height[], int month[], int n, int m)
{
	int maxHeight = -1;
	for (int i = n - 1; i >= 0; i--)
		if (month[i] == m)
		{
			maxHeight = height[i];
			break;
		}
	return maxHeight;
}

int main()
{
	int n, m;
	int* height;
	int* month;

	scanf("%d", &n);
	height = new int[n];
	month = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &height[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &month[i]);
	scanf("%d", &m);

	int answer = getMaximumHeight(height, month, n, m);
	printf("%d\n", answer);

	delete[] height;
	delete[] month;
	return 0;
}