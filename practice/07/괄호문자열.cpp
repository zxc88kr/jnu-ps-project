// 문제해결프로젝트 실습 07 (1)
// 학번 : 195443
// 이름 : 박찬

#include <iostream>
#include <string>
#include <vector>
#include <stack>

/**
 * 주어진 문자가 올바른 괄호 문자열인지 확인하는 함수
 * @param str 대상이 되는 문자
 * @return 	  주어진 문자가 올바른 괄호 문자열이면 true, 그렇지 않으면 false를 반환
 */
bool isValidPS(std::string str)
{
	std::stack<bool> st; // 스택을 사용
	for (int i = 0; i < str.length(); i++) // 각 문자를 순차적으로 탐색
	{
		if (str[i] == '(') st.push(true); // 해당 문자가 '('일 경우 스택에 값을 하나 추가
		else if (str[i] == ')') // 해당 문자가 ')'일 경우
		{
			if (st.size() > 0) st.pop(); // 스택이 비어 있지 않은 경우 스택에서 값을 하나 제거
			else return false; // 스택이 비어 있는 경우 false를 반환
		}
	}
	if (st.size() == 0) return true; // 탐색이 끝나고 나서 스택이 비어 있는 경우 true를 반환
	else return false; // 그게 아니라면 false를 반환
}

int main()
{
	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		std::string str;
		std::cin >> str;
		
		if (isValidPS(str)) std::cout << "YES\n";
		else				std::cout << "NO\n";
	}

	return 0;
}