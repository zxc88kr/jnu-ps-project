#include <cstdio>
#include <cmath>

int findIndex(int data[], int n)
{
	int sum = 0, x = 0;
	for (int i = 0; i < n; i++)
		sum += data[i];

	for (int i = 0; i < n; i++)
	{
		int dx = abs(n * data[x] - sum);
		int di = abs(n * data[i] - sum);
		if (dx > di) x = i;
	}
	return x + 1;
}

int main()
{
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	
	int answer = findIndex(data, n);
	printf("%d %d\n", answer, data[answer - 1]);

	delete[] data;
	return 0;
}