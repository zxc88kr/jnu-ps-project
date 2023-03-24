#include <cstdio>

void bubbleSort(int data[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int negativeCount = 0;
		for (int j = 0; j < n - 1 - i; j++)
			if (data[j] > data[j + 1])
			{
				int temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
				negativeCount++;
			}
		if (negativeCount == 0) break;
	}
}

int main()
{
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);

	bubbleSort(data, n);

	for (int i = 0; i < n; i++)
	{
		if (i > 0) printf(" ");
		printf("%d", data[i]);
	}
	printf("\n");

	delete[] data;
	return 0;
}