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
int getMaximumScore(int a, int b, std::vector<int>& cardA, std::vector<int>& cardB)
{
	int maximumScore = 0; // 얻을 수 있는 최대 점수를 0으로 초기화
	for (int beginB = 0; beginB < b; beginB++) // 두 번째 카드 더미를 기준으로 비교 진행, 카드 더미 위에서 버릴 카드 수를 구함
	{
		if (b - beginB <= maximumScore) break; // 최대 비교 횟수가 현재 최대 점수보다 작거나 같으면 반복문 종료
											   // 비교 결과가 전부 동일하다고 해도 최대 점수를 넘지 못해 업데이트가 일어나지 않기 때문

		int idxA = 0; // 첫 번째 카드 더미는 첫 카드부터 비교 시작
		int idxB = beginB; // 두 번째 카드 더미는 위에서 버린 카드들 다음 카드부터 비교 시작
		int matchScore = 0; // 비교 결과 두 카드의 숫자가 동일하면 값을 1 증가

		while (idxA < a && idxB < b) // 두 카드 더미 중 어느 하나라도 탐색이 끝나면 비교 종료
		{
			if (cardA[idxA] == cardB[idxB]) // 두 카드의 숫자가 동일한 경우
			{
				idxB++; // 두 번째 카드 더미의 다음 카드를 탐색
				matchScore++; // matchScore 값을 1 증가
			}
			idxA++; // 첫 번째 카드 더미의 다음 카드를 탐색
		}
		maximumScore = ((matchScore > maximumScore) ? matchScore : maximumScore); // 최대 점수 업데이트
	}
	return maximumScore; // 최대 점수 반환

	// 예시 (첫 번째 카드더미는 (4 5 2 4), 두 번째 카드더미는 (4 5 4 2) 라고 가정)
	// (첫 번째 반복문: 0번째 인덱스부터 시작) -> (4), (4 5), (4 5 4), (4 5 4 2) 순으로 탐색 -> (4 5 4) 일치 -> 최대 점수 3 -> 업데이트
	// (두 번째 반복문: 1번째 인덱스부터 시작) -> (5), (5 4), (5 4 2) 순으로 탐색 -> (5 4) 일치 -> 최대 점수 2
    // (세 번째 반복문: 2번째 인덱스부터 시작) -> (4), (4 2) 순으로 탐색 -> (4 2) 일치 -> 최대 점수 2
	// (네 번째 반복문: 3번째 인덱스부터 시작) -> (2) 순으로 탐색 -> (2) 일치 -> 최대 점수 1
	// break 조건문에 따라 두 번째 반복문부터는 수행되지 않음
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
	
	int maximumScore = getMaximumScore(a, b, cardA, cardB);
	printf("%d\n", maximumScore);

	clock_t end = clock(); // 시간 측정 종료

	printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}