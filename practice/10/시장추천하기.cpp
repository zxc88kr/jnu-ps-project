// 문제해결프로젝트 실습 10 (2)
// 학번 : 195443
// 이름 : 박찬

#include <iostream>
#include <string>
#include <map>

int main()
{
	int n;
	std::cin >> n;

	std::map<std::string, int> frequencyMap; // 후보자들의 등장 빈도수를 저장하는 맵
	int maxFrequency = 0;

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;

		if (frequencyMap.count(str) == 0) // 사용자가 입력한 후보자가 처음 등장하는 후보자인 경우
			frequencyMap[str] = 0; // 빈도수를 0으로 초기화
		frequencyMap[str]++; // 사용자가 입력한 후보자의 빈도수를 1 증가

		int frequency = frequencyMap[str];
		maxFrequency = ((frequency > maxFrequency) ? frequency : maxFrequency); // 현재 후보자의 빈도수를 기준으로 최대 빈도수 업데이트
	}

	std::cout << maxFrequency << '\n'; // 최대 빈도수
	for (auto it = frequencyMap.begin(); it != frequencyMap.end(); it++)
		if (it->second == maxFrequency) // 최대 빈도수에 해당하는 후보자들을 공백으로 구분하여 출력
			std::cout << it->first.c_str() << ' ';
	std::cout << '\n';

	return 0;
}