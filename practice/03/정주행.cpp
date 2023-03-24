// 문제해결프로젝트 실습 03 (5)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

bool isConsecutive(int data[], int n)
{
	int minData = data[0];
	int maxData = data[0];

	for (int i = 1; i < n; i++)
	{
		if (data[i] < minData) minData = data[i];
		else if (data[i] > maxData) maxData = data[i];
	}

	if (maxData - minData == n - 1) return true;
	return false;
}

int main()
{
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);

	bool result = isConsecutive(data, n);

	if (result) printf("YES\n");
	else		printf("NO\n");

	delete[] data;
	return 0;
}