// 문제해결프로젝트 프로젝트 02 (2)
// 학번 : 195443
// 이름 : 박찬

#include <iostream> // 표준 입출력 라이브러리
#include <string> // 문자열 라이브러리
#include <vector> // 벡터 라이브러리
#include <ctime> // 시간 라이브러리

/**
 * 주어진 문자열의 오른쪽에서 왼쪽 방향으로 발견되는 최대 길이의 회문들을 각 줄마다 출력하는 함수
 * @param str 주어진 문자열
 */
void printLongestPalindromes(std::string& str)
{
	int strLen = str.length(); // 주어진 문자열의 길이

	// 회문의 길이: 문자열의 길이 ~> 2
	for (int palLen = strLen; palLen >= 2; palLen--)
	{
		bool havePalindrome = false; // 문자열에서 해당 길이의 회문이 발견되는지 확인, 초기값은 false

		// 탐색 대상 기준점: 문자열의 길이 - 회문의 길이 ~> 0
		for (int base = strLen - palLen; base >= 0; base--)
		{
			bool isPalindrome = true; // 탐색 대상이 회문인지 확인, 초기값은 true

            // 주어진 문자열의 탐색 대상 기준점부터 해당 길이만큼의 새로운 문자열이 회문인지 확인 (중심을 기점으로 대칭인지 확인)
			for (int offset = 0; offset < palLen / 2; offset++)
				if (str[base + offset] != str[base + palLen - offset - 1])
				{
					isPalindrome = false; // 대칭이 아닌 경우, 탐색 대상이 회문이 아님을 체크
					break; // 다음 기준점으로 이동
				}

			// 탐색 대상이 회문인 경우
			if (isPalindrome)
			{
				havePalindrome = true; // 문자열에서 해당 길이의 회문이 발견되었음을 체크
				std::cout << str.substr(base, palLen) << '\n'; // 주어진 문자열의 탐색 대상 기준점부터 해당 탐색 길이만큼 출력, 다음 기준점으로 이동
			}
		}

        // 문자열에서 해당 길이의 회문이 발견되었다면 탐색 종료, 그게 아니라면 회문의 길이를 1글자 줄여서 위 과정을 반복
		if (havePalindrome) return; 
	}

	// 예시 (문자열의 길이는 5, 하나의 문자열을 (1 2 3 4 5)로 나타냄, 번호는 각각의 인덱스라고 가정)
	// (첫 번째 반복문: 5글자 회문) -> (1 2 3 4 5) 순으로 탐색
	// (두 번째 반복문: 4글자 회문) -> (2 3 4 5), (1 2 3 4) 순으로 탐색
    // (세 번째 반복문: 3글자 회문) -> (3 4 5), (2 3 4), (1 2 3) 순으로 탐색
    // (네 번째 반복문: 2글자 회문) -> (4 5), (3 4), (2 3), (1 2) 순으로 탐색
    // 탐색 대상이 되는 문자열이 회문인지 확인
    // 탐색 도중 특정 반복문에서 회문이 발견되는 경우
    // 해당 반복문까지만 탐색을 진행하고 종료, 그 이후 반복문은 수행하지 않음 (최대 길이의 회문만을 구함)
}

int main()
{
	int t;
	std::cin >> t;

	std::vector<std::string> str(t); // 입력 문자열을 저장하는 벡터
	for (int idx = 0; idx < t; idx++)
		std::cin >> str[idx];

	clock_t start = clock(); // 시간 측정 시작

	for (int idx = 0; idx < t; idx++)
	{
		std::cout << "Case #" << idx + 1 << ":\n"; // 실제 번호는 1부터 시작
		printLongestPalindromes(str[idx]);
	}

	clock_t end = clock(); // 시간 측정 종료

	printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}