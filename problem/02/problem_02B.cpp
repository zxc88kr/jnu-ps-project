#include <cstdio>

bool isOrdered(int data[], int n)
{
	bool result = true;
	for (int i = 0; i < n - 1; i++)
		if (data[i] > data[i + 1])
		{
			result = false;
			break;
		}
	return result;
}

int main()
{
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];

	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);

	bool result = isOrdered(data, n);
	if (result) printf("YES\n");
	else		printf("NO\n");

	delete[] data;
	return 0;
}