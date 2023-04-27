// 문제해결프로젝트 프로젝트 03 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio> // 표준 입출력 라이브러리
#include <vector> // 벡터 라이브러리
#include <cmath> // 수학 라이브러리
#include <algorithm> // 알고리즘 라이브러리
#include <ctime> // 시간 라이브러리

/**
 * 중복을 포함한 세 카드의 합으로 만들 수 있는 당첨번호 벡터를 반환하는 함수
 * @param n			  카드의 수
 * @param shortLength 카드 벡터 shortLength[0] ~ shortLength[n - 1]
 * @param longLength  당첨번호 벡터 longLength[0] ~ longLength[n - 1]
 * @return			  중복을 포함한 세 카드의 합으로 만들 수 있는 당첨번호 벡터를 반환
 */
int solve(int n, std::vector<int>& shortLength, std::vector<int>& longLength)
{
	std::vector<int> lastStandRound(n);
	std::vector<int> lastLieRound(n);
	lastStandRound[0] = shortLength[0];
	lastLieRound[0] = longLength[0];

	for (int i = 1; i < n; i++)
	{
		int previousShort = shortLength[i - 1];
		int previousLong = longLength[i - 1];
		int currentShort = shortLength[i];
		int currentLong = longLength[i];

		lastStandRound[i] = std::max(lastStandRound[i - 1] + std::abs(currentLong - previousLong) + currentShort, // 서있고 서있다
									lastLieRound[i - 1] + std::abs(currentLong - previousShort) + currentShort); // 누워있고 서있다
		lastLieRound[i] = std::max(lastStandRound[i - 1] + std::abs(currentShort - previousLong) + currentLong, // 서있고 누워있다
								  lastLieRound[i - 1] + std::abs(currentShort - previousShort) + currentLong); // 누워있고 누워있다
	}
	return std::max(lastStandRound[n - 1], lastLieRound[n - 1]);
}

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> shortLength(n);
	std::vector<int> longLength(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &shortLength[i], &longLength[i]);
	
	clock_t start = clock(); // 시간 측정 시작
	
	int round = solve(n, shortLength, longLength);
	printf("%d\n", round);

	clock_t end = clock(); // 시간 측정 종료

	printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}