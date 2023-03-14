// 문제해결프로젝트 실습 01 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

/**
 * 동아리 멤버들의 놀이기구 탑승 가능 여부를 출력하는 함수
 * @param data 멤버들의 몸무게 배열 data[0] ~ data[n - 1]
 * @param n    멤버들의 수
 * @param p    놀이기구 탑승 가능 체중 제한
 * @param q    놀이기구 최대 하중 제한
 */
void solve(int data[], int n, int p, int q)
{
	int count = 0; // 탑승 가능한 멤버의 수
	int weight_sum = 0; // 탑승 가능한 멤버의 몸무게 총합
	for (int i = 0; i < n; i++)
		if (data[i] <= p)
		{
			count++;
			weight_sum += data[i];
		}

	printf("%d %d\n", count, weight_sum);
	if (weight_sum <= q) printf("YES\n");
	else 				 printf("NO\n");
}

int main()
{
	int n, p, q;
	int* data;

	scanf("%d %d %d", &n, &p, &q);
	data = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &data[i]);
	
	solve(data, n, p, q);

	delete[] data;
	return 0;
}