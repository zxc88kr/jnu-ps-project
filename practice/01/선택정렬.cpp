// 문제해결프로젝트 실습 01 (5)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

int getMinIndexInRange(int data[], int n, int begin, int end)
{
	int index = begin;
	for (int i = begin; i <= end; i++)
		if (data[i] < data[index])
			index = i;
	return index;
}

void selectionSort(int data[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int minIndex = getMinIndexInRange(data, n, i, n - 1);
		
		int temp = data[minIndex];
		data[minIndex] = data[i];
		data[i] = temp;
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

	selectionSort(data, n);

	for (int i = 0; i < n; i++)
	{
		if (i > 0) printf(" ");
		printf("%d", data[i]);
	}
	printf("\n");

	delete[] data;
	return 0;
}