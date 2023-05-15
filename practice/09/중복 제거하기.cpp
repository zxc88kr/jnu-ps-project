// 문제해결프로젝트 실습 09 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <set>

int main()
{
	int n;
	scanf("%d", &n);

	std::set<int> nSet; // 사용자가 입력한 숫자를 저장하는 Set (중복을 허용하지 않음)
	for (int i = 0; i < n; i++) // 사용자가 입력한 숫자를 대상으로 순서대로 탐색
	{
		int num;
		scanf("%d", &num);

		if (nSet.count(num) > 0) // 사용자가 입력한 숫자가 이미 앞서 등장한 적 있는 숫자인 경우
			printf("DUPLICATED\n");
		else // 사용자가 입력한 숫자가 처음 등장하는 숫자인 경우
		{
			nSet.insert(num); // Set에 해당 숫자를 insert
			printf("OK\n");
		}
	}

	return 0;
}