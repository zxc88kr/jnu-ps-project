// 문제해결프로젝트 프로젝트 03 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio> // 표준 입출력 라이브러리
#include <vector> // 벡터 라이브러리
#include <ctime> // 시간 라이브러리

/**
 * 주어진 두 카드 더미로 게임을 했을 때 얻을 수 있는 최대 점수를 반환하는 함수
 * @param a		첫 번째 카드 더미의 카드 수
 * @param b		두 번째 카드 더미의 카드 수
 * @param cardA 첫 번째 카드 더미 벡터 cardA[0] ~ cardA[a - 1]
 * @param cardB 두 번째 카드 더미 벡터 cardB[0] ~ cardB[b - 1]
 * @return		주어진 두 카드 더미로 게임을 했을 때 얻을 수 있는 최대 점수를 반환
 */
int getMaxScore(int a, int b, std::vector<int>& cardA, std::vector<int>& cardB)
{
	int maxScore = 0; // 얻을 수 있는 최대 점수를 0으로 초기화
	for (int beginB = 0; beginB < b; beginB++) // 두 번째 카드 더미를 기준으로 비교 진행, 카드 더미 위에서 버릴 카드 수를 구함
	{
		int idxA = 0; // 첫 번째 카드 더미는 첫 카드부터 비교 시작
		int idxB = beginB; // 두 번째 카드 더미는 위에서 버린 카드들 다음 카드부터 비교 시작
		int match = 0; // 비교 결과 두 카드가 동일

		while (idxA < a && idxB < b) // 두 카드 더미 중 어느 하나라도 탐색이 끝나면 비교 종료
		{
			if (cardA[idxA] == cardB[idxB]) // 두 카드의 숫자가 동일한 경우
			{
				idxB++; // 두 번째 카드 더미의 다음 카드를 탐색
				match++; // 일치 결과 1 증가
			}
			idxA++; // 첫 번째 카드 더미의 다음 카드를 탐색
		}
		maxScore = ((match > maxScore) ? match : maxScore); // 최대 점수 업데이트
	}
	return maxScore; // 최대 점수 반환
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

	clock_t start = clock(); // 시간 측정 시작
	
	int maxScore = getMaxScore(a, b, cardA, cardB);
	printf("%d\n", maxScore);

	clock_t end = clock(); // 시간 측정 종료

	printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}