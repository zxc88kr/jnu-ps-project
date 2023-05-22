// 문제해결프로젝트 실습 10 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <map>

int main()
{
	int n;
	scanf("%d", &n);

	std::map<int, int> frequencyMap; // 숫자들의 등장 빈도수를 저장하는 맵
	
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);

		if (frequencyMap.count(num) == 0) // 사용자가 입력한 숫자가 처음 등장하는 숫자인 경우
			frequencyMap[num] = 0; // 빈도수를 0으로 초기화
		frequencyMap[num]++; // 사용자가 입력한 숫자의 빈도수를 1 증가
	
		printf("%d %d\n", frequencyMap.size(), frequencyMap[num]); // 현재까지의 숫자 종류의 개수와 현재 숫자의 빈도수를 출력
	}

	return 0;
}