// 문제해결프로젝트 실습 07 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <vector>
#include <stack>

/**
 * 주어진 탑의 높이 벡터로부터 레이저 신호를 수신한 탑들의 번호를 하나씩 출력하는 함수
 * @param towers 탑의 높이 벡터 towers[0] ~ towers[n - 1]
 * @param n		 탑의 수
 */
void solve(std::vector<int>& towers, int n)
{
	std::stack<int> stackHeight; // 탑의 높이를 저장하는 스택
	std::stack<int> stackIndex; // 탑의 인덱스 번호를 저장하는 스택

	for (int i = 0; i < n; i++) // 모든 탑을 대상으로 탐색
	{
		int targetTowerIndex = 0; // 레이저 신호를 수신한 탑이 존재하지 않으면 기본적으로 0을 출력

		// 현재 탑의 높이보다 낮은 탑들은 레이저를 수신하지 못하므로, 이에 해당하는 탑들을 전부 스택에서 제거
		while (stackHeight.size() > 0 && stackHeight.top() < towers[i])
		{
			stackHeight.pop();
			stackIndex.pop();
		}
		
		if (stackHeight.size() > 0) // 현재 탑의 높이보다 높은 탑이 존재하는 경우
			targetTowerIndex = stackIndex.top(); // 그 중 첫 번째로 만나는 탑이 바로 레이저 신호를 수신한 탑

		if (i > 0) printf(" "); // 각 데이터는 공백으로 구분
		printf("%d", targetTowerIndex);

		stackHeight.push(towers[i]); // 현재 탑의 높이를 스택에 추가
		stackIndex.push(i + 1); // 현재 탑의 인덱스 번호를 스택에 추가, 실제 인덱스는 1부터 시작
	}
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);

	std::vector<int> towers(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &towers[i]);

	solve(towers, n);

	return 0;
}