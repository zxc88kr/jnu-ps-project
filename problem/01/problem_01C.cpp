#include <cstdio>

int getCount(int data[], int n, int m, int s)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (data[i] == m || data[i] == s)
            count++;
	return count;
}

int main()
{
	int n, m, s;
	int* data;

	scanf("%d %d %d", &n, &m, &s);
	data = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	
	int answer = getCount(data, n, m, s);
	printf("%d\n", answer);

	delete[] data;
	return 0;
}