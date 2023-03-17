// 문제해결프로젝트 실습 02 (4)
// 학번 : 195443
// 이름 : 박찬

#include <iostream>
#include <string>

/**
 * 두 문자열을 사전순으로 비교하여 그 결과를 반환하는 함수
 * @param s1 소문자로 구성된 첫 번째 문자열
 * @param s2 소문자로 구성된 두 번째 문자열
 * @return 	 첫 번째 문자열이 사전순으로 앞서면 -1, 그렇지 않으면 1, 두 문자열이 일치하면 0을 반환
 */
int getComparison(std::string s1, std::string s2)
{
	int order = 0; // 문자열의 사전순 비교 결과
	int len = 0; // 문자열의 길이 (두 문자열을 비교할 횟수)

	int len1 = s1.length(); // 첫 번째 문자열의 길이
	int len2 = s2.length(); // 두 번째 문자열의 길이
	len = len1 < len2 ? len1 : len2; // 두 문자열 중 짧은 문자열의 길이를 저장

	// 예외가 발생하지 않는 한, 출력하게 될 비교 결과를 초기화
	if (len1 == len2)	  order = 0; // 두 문자열의 길이가 동일
	else if (len1 < len2) order = -1; // 첫 번째 문자열의 길이가 더 짧음
	else if (len1 > len2) order = 1; // 두 번째 문자열의 길이가 더 짧음

	for (int i = 0; i < len; i++) // 짧은 문자열의 길이만큼 두 문자열을 비교 탐색
	{
		if (s1[i] == s2[i]) continue; // 현재 위치의 문자가 동일하면, 다음 위치의 문자를 비교
		else if (s1[i] < s2[i])
		{
			order = -1;
			break;
		}
		else if (s1[i] > s2[i])
		{
			order = 1;
			break;
		}
	}
	return order;
}

int main()
{
	std::string s1;
	std::string s2;
	std::cin >> s1 >> s2;

	int answer = getComparison(s1, s2);
	std::cout << answer << '\n';

	return 0;
}