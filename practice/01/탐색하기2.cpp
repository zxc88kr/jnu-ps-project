// 문제해결프로젝트 실습 01 (3)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <string>

/**
 * 배열에서 소속 학교명이 "AJOU"인 처음과 마지막 데이터의 인덱스를 출력하는 함수
 * @param school 학생들의 소속 학교명 배열 school[0] ~ school[n - 1]
 * @param n 	 학생들의 수
 */
void printIndexes(std::string school[], int n)
{
	int first = -1; // 처음으로 발견된 데이터의 인덱스를 -1로 초기화
	int last = -1; // 마지막으로 발견된 데이터의 인덱스를 -1로 초기화
	for (int i = 0; i < n; i++)
		if (school[i] == "AJOU")
		{
			if (first == -1) first = i + 1; // first는 처음 발견된 한 번만 업데이트
			last = i + 1; // last는 발견될 때마다 업데이트
		}
	printf("%d %d\n", first, last);
}

int main()
{
	int n;
	char buff[11]; // 소속 학교명은 10글자 이하
	std::string* school;

	scanf("%d", &n);
	school = new std::string[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", buff);
		school[i] = buff;
	}
	
	printIndexes(school, n);

	delete[] school;
	return 0;
}