#include <cstdio>

int getElementTypeCount(int data[], int n)
{
	int typeCount = 1;
	for (int i = 1; i < n; i++)
		if (data[i - 1] != data[i])
			typeCount++;
	return typeCount;
}

int main()
{
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);

	int answer = getElementTypeCount(data, n);
	printf("%d\n", answer);

	delete[] data;
	return 0;
}