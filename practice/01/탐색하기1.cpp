// 문제해결프로젝트 실습 01 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

int findIndex(int data[], int n, int m)
{
	int index = -1;
	for (int i = 0; i < n; i++)
		if (data[i] == m)
		{
			index = i;
			break;
		}
	return index;
}

int main()
{
	int n, m;
	int* data;

	scanf("%d %d", &n, &m);
	data = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	
	int answer = findIndex(data, n, m);
	printf("%d\n", answer);

	delete[] data;
	return 0;
}