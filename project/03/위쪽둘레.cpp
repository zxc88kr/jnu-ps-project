// 문제해결프로젝트 프로젝트 03 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio> // 표준 입출력 라이브러리
#include <vector> // 벡터 라이브러리
#include <cmath> // 수학 라이브러리
#include <algorithm> // 알고리즘 라이브러리
#include <ctime> // 시간 라이브러리

/**
 * 주어진 사각형을 놓았을 때 가장 길어지는 위쪽 둘레의 길이를 반환하는 함수
 * @param n			사각형의 수
 * @param shortSide 사각형의 짧은 변 벡터 shortSide[0] ~ shortSide[n - 1]
 * @param longSide	사각형의 긴 변 벡터 longSide[0] ~ longSide[n - 1]
 * @return			주어진 사각형을 놓았을 때 가장 길어지는 위쪽 둘레의 길이를 반환
 */
int getLongestPerimeter(int n, std::vector<int>& shortSide, std::vector<int>& longSide)
{
	std::vector<int> lastStandPerimeter(n); // 마지막으로 놓인 사각형이 서있을 때 가장 길어지는 위쪽 둘레의 길이
	std::vector<int> lastLiePerimeter(n); // 마지막으로 놓인 사각형이 누워있을 때 가장 길어지는 위쪽 둘레의 길이
	lastStandPerimeter[0] = shortSide[0]; // 사각형 하나가 서있으므로 위쪽 둘레는 짧은 변의 길이
	lastLiePerimeter[0] = longSide[0]; // 사각형 하나가 누워있으므로 위쪽 둘레는 긴 변의 길이

	for (int i = 1; i < n; i++)
	{
		int previousShort = shortSide[i - 1]; // 이전에 놓인 사각형의 짧은 변의 길이
		int previousLong = longSide[i - 1]; // 이전에 놓인 사각형의 긴 변의 길이
		int currentShort = shortSide[i]; // 현재 놓을 사각형의 짧은 변의 길이
		int currentLong = longSide[i]; // 현재 놓을 사각형의 긴 변의 길이

		// 현재 사각형을 서있게 놓았을 때 가장 길어지는 위쪽 둘레의 길이
		lastStandPerimeter[i] = std::max(lastStandPerimeter[i - 1] + std::abs(currentLong - previousLong), // 이전 사각형 서있음, 현재 사각형 서있음
										 lastLiePerimeter[i - 1] + std::abs(currentLong - previousShort)) // 이전 사각형 누워있음, 현재 사각형 서있음
										 + currentShort; // 사각형 하나가 서있으므로 마지막 위쪽 둘레는 짧은 변의 길이
		// 현재 사각형을 누워있게 놓았을 때 가장 길어지는 위쪽 둘레의 길이
		lastLiePerimeter[i] = std::max(lastStandPerimeter[i - 1] + std::abs(currentShort - previousLong), // 이전 사각형 서있음, 현재 사각형 누워있음
									   lastLiePerimeter[i - 1] + std::abs(currentShort - previousShort)) // 이전 사각형 누워있음, 현재 사각형 누워있음
									   + currentLong; // 사각형 하나가 누워있으므로 마지막 위쪽 둘레는 긴 변의 길이
	}
	return std::max(lastStandPerimeter[n - 1], lastLiePerimeter[n - 1]); // 두 가지 경우에서 더 긴 위쪽 둘레의 길이를 반환
}

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> shortSide(n);
	std::vector<int> longSide(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &shortSide[i], &longSide[i]);
	
	clock_t start = clock(); // 시간 측정 시작
	
	int longestPerimeter = getLongestPerimeter(n, shortSide, longSide);
	printf("%d\n", longestPerimeter);

	clock_t end = clock(); // 시간 측정 종료

	printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}