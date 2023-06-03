// 문제해결프로젝트 프로젝트 05 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio> // 표준 입출력 라이브러리
#include <cstring> // 문자열 라이브러리
#include <cmath> // 수학 라이브러리
#include <algorithm> // 알고리즘 라이브러리
#include <ctime> // 시간 라이브러리

const int MAX = 16; // 고양이의 최대 마리 수
const int INF = 1e9; // int 정수형의 최대값을 대략적으로 표현 (min 함수 사용 목적)

int n; // 고양이의 수
int x[MAX + 1], y[MAX + 1]; // 고양이의 x, y 위치 좌표
int dp[MAX + 1][1 << (MAX + 1)]; // 최소 시간을 구하기 위한 2차원 배열 (DP 알고리즘)

/**
 * 모든 고양이에게 밥을 주기 위해 필요한 최소 시간을 반환하는 함수
 * @param current 현재 배식 받을 고양이의 인덱스
 * @param visited 현재 고양이들의 배식 현황 (인덱스들을 하나의 문자열로 표현)
 * @return        모든 고양이에게 밥을 주기 위해 필요한 최소 시간을 반환
 */
int getMinimumTimeFeedingCats(int current, int visited)
{
	int& ret = dp[current][visited]; // 2차원 DP 배열에 대한 레퍼런스를 설정

	// ret가 참조된 적 없는 경우, ret를 INF로 초기화
	if (ret == -1) ret = INF;
	else 		   return ret;

	// 모든 고양이에게 배식을 하고 난 뒤 교문으로 되돌아감
	if (visited == (1 << (n + 1)) - 1)
		return x[current] + y[current];
	
	// 모든 고양이를 대상으로 배식을 진행, 순서는 정해지지 않음
	for (int next = 1; next <= n; next++)
	{
		// 배식이 완료된 고양이는 다시 배식하지 않음
		if ((visited & (1 << next)) > 0) continue;

		// visited 값에 next 비트를 추가하여 재귀적으로 호출
		int temp = getMinimumTimeFeedingCats(next, visited | (1 << next)) +
				   std::abs(x[next] - x[current]) + std::abs(y[next] - y[current]);
		ret = std::min(temp, ret);
	}

	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &x[i], &y[i]);

	clock_t start = clock(); // 시간 측정 시작

	std::memset(dp, -1, sizeof(dp)); // 2차원 DP 배열의 원소 값을 전부 -1로 초기화

	int minimumTimeFeedingCats = getMinimumTimeFeedingCats(0, 1);
	printf("%d\n", minimumTimeFeedingCats);

	clock_t end = clock(); // 시간 측정 종료

    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    return 0;
}