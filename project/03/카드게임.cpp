// 문제해결프로젝트 프로젝트 03 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <vector>

void solve(int a, int b, std::vector<int>& cardA, std::vector<int>& cardB)
{
	int maxScore = 0;
	for (int beginB = 0; beginB < b; beginB++)
	{
		int idxA = 0;
		int idxB = beginB;
		int match = 0;

		while (idxA < a && idxB < b)
		{
			if (cardA[idxA] == cardB[idxB])
			{
				idxB++;
				match++;
			}
			idxA++;
		}
		maxScore = ((match > maxScore) ? match : maxScore);
	}
	printf("%d\n", maxScore);
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	std::vector<int> cardA(a);
	for (int i = 0; i < a; i++)
		scanf("%d", &cardA[i]);

	std::vector<int> cardB(b);
	for (int i = 0; i < b; i++)
		scanf("%d", &cardB[i]);

	solve(a, b, cardA, cardB);

	return 0;
}