// 문제해결프로젝트 실습 11 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

#define MAX_DEPTH 8 // 그래프의 최대 깊이

bool connected[MAX_DEPTH + 1][MAX_DEPTH + 1] = { false, }; // 인접 행렬을 false로 초기화
bool visited[MAX_DEPTH + 1] = { false, }; // 방문 여부 배열을 false로 초기화

/**
 * 깊이우선탐색 방법으로 그래프를 순회하며 탐색한 노드들을 순서대로 하나씩 출력하는 함수
 * @param v 현재 탐색 중인 노드의 번호
 */
void dfs(int v)
{
	printf("%d\n", v); // 현재 노드를 출력
	visited[v] = true; // 현재 노드의 방문 여부를 true로 체크

	// 연결된 노드들 중에서 아직 방문하지 않은 노드들을 재귀적으로 탐색
	for (int i = 1; i <= MAX_DEPTH; i++)
		if (connected[v][i] && !visited[i])
			dfs(i);
}

int main()
{
	int edge_num;
	scanf("%d", &edge_num);

	for (int i = 0; i < edge_num; i++)
	{
		// 그래프 노드 간의 연결 상태를 입력 받은 뒤 인접 행렬에 반영
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		connected[v1][v2] = connected[v2][v1] = true;
	}
	
	dfs(1); // 1번 노드부터 탐색 시작
	
	return 0;
}