// 문제해결프로젝트 프로젝트 02 (1)
// 학번 : 195443
// 이름 : 박찬

#include <iostream> // 표준 입출력 라이브러리
#include <algorithm> // 알고리즘 라이브러리
#include <ctime> // 시간 라이브러리

/**
 * 주어진 숫자를 출력하고 줄바꿈하는 함수
 * @param num 출력하고자 하는 숫자
 */
void printNumber(int num)
{
	std::cout << num << '\n';
}

/**
 * 주어진 점수에 해당하는 점수판을 주어진 횟수만큼 반복하여 각 줄마다 출력하는 함수 (l_score:r_score)
 * @param l_score 왼쪽에 표시할 점수
 * @param r_score 오른쪽에 표시할 점수
 * @param repeat  출력을 반복할 횟수
 */
void printScoreBoardByRepeat(int l_score, int r_score, int repeat)
{
	for (int i = 0; i < repeat; i++)
		std::cout << l_score << ':' << r_score << '\n';
}

/**
 * 득점한 골의 합, 실점한 골의 합, 총 경기 수를 이용하여 문제를 해결하는 함수
 * @param a 득점한 골의 합
 * @param b 실점한 골의 합
 * @param n 총 경기 수
 */
void solve(int a, int b, int n)
{
	// 1경기만 하는 경우
	// x:x 무승부 경기가 존재할 수 있음
	if (n == 1)
	{
		if (a == b) printNumber(1); // 득점 == 실점인 경우, 최소 무승부 횟수는 1
		else		printNumber(0); // 득점 != 실점인 경우, 최소 무승부 횟수는 0

		printScoreBoardByRepeat(a, b, 1); // a:b (1번 출력)

		// 예시
		// (a = 2, b = 2, n = 1) -> (2:2) -> 1번
		// (a = 2, b = 3, n = 1) -> (2:3) -> 0번
	}

	// 득점 + 실점 <= 경기 수인 경우
	// 0:0 무승부 경기가 존재할 수 있음
	else if (a + b <= n)
	{
		printNumber(n - a - b); // 최소 무승부 횟수는 (n-a-b)
								// n번의 경기에서 a번은 1:0, b번은 0:1, 나머지 n-a-b번은 0:0

		printScoreBoardByRepeat(1, 0, a); // 1:0 (a번 출력)
		printScoreBoardByRepeat(0, 1, b); // 0:1 (b번 출력)
		printScoreBoardByRepeat(0, 0, n - a - b); // 0:0 (n-a-b번 출력)

		// 예시
		// (a = 1, b = 2, n = 3) -> (1:0, 0:1, 0:1) -> 0번
		// (a = 1, b = 2, n = 4) -> (1:0, 0:1, 0:1, 0:0) -> 1번
	}

	// 득점 + 실점 > 경기 수인 경우
	// 무승부 경기가 존재할 수 없음
	else if (a + b > n)
	{
		printNumber(0); // 최소 무승부 횟수는 0
						// 득점 < 실점인 경우
						// 마지막 1경기를 제외한 앞의 경기들을 1:0 의 경기들로 채움
						// 마지막 1경기를 제외하고도 여유 경기가 있다면 나머지 경기들을 0:1 의 경기들로 채움
						// 마지막 1경기는 a:b (앞의 경기에 의한 점수의 변화에 유의)
						// 득점 >= 실점인 경우
						// 마지막 1경기를 제외한 앞의 경기들을 0:1 의 경기들로 채움
						// 마지막 1경기를 제외하고도 여유 경기가 있다면 나머지 경기들을 1:0 의 경기들로 채움
						// 마지막 1경기는 a:b (앞의 경기에 의한 점수의 변화에 유의)
						// 더 적은 점수부터 사용하는 이유는 점수를 차감하는 과정에서 무승부가 발생하는 것을 막기 위함

		if (a < b) // 득점 < 실점인 경우
		{
			int loop = std::min(a, n - 1); // 마지막 1경기를 남기기 위해 이와 같은 방법을 사용
			if (loop > 0) // 채울 수 있는 경기가 존재하는 경우
			{
				printScoreBoardByRepeat(1, 0, loop); // 1:0 (loop번 출력)
				a -= loop; // 사용한 득점만큼 차감
			}
			if (n - 1 - loop > 0) // 채울 수 있는 경기가 존재하는 경우
			{
				printScoreBoardByRepeat(0, 1, n - 1 - loop); // 0:1 (n-1-loop번 출력)
				b -= (n - 1 - loop); // 사용한 실점만큼 차감
			}
			printScoreBoardByRepeat(a, b, 1); // a:b (1번 출력)
		}
		else if (a >= b) // 득점 >= 실점인 경우
		{
			int loop = std::min(b, n - 1); // 마지막 1경기를 남기기 위해 이와 같은 방법을 사용
			if (loop > 0) // 채울 수 있는 경기가 존재하는 경우
			{
				printScoreBoardByRepeat(0, 1, loop); // 0:1 (loop번 출력)
				b -= loop; // 사용한 실점만큼 차감
			}
			if (n - 1 - loop > 0) // 채울 수 있는 경기가 존재하는 경우
			{
				printScoreBoardByRepeat(1, 0, n - 1 - loop); // 1:0 (n-1-loop번 출력)
				a -= (n - 1 - loop); // 사용한 득점만큼 차감
			}
			printScoreBoardByRepeat(a, b, 1); // a:b (1번 출력)
		}

		// 예시
		// (a = 2, b = 4, n = 4) -> (1:0, 1:0, 0:1, 0:3) -> 0번
		// (a = 4, b = 2, n = 4) -> (0:1, 0:1, 1:0, 3:0) -> 0번
		// (a = 3, b = 4, n = 3) -> (1:0, 1:0, 1:4) -> 0번
		// (a = 4, b = 3, n = 3) -> (0:1, 0:1, 4:1) -> 0번
	}
}

int main()
{
	int n; // 총 경기 수
	int a; // 득점한 골의 합
	int b; // 실점한 골의 합

	std::cin >> n >> a >> b;

	clock_t start = clock(); // 시간 측정 시작

	solve(a, b, n);

	clock_t end = clock(); // 시간 측정 종료

	printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}