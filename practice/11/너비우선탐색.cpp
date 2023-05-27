// 문제해결프로젝트 실습 11 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <queue>

#define MAX_DEPTH 8 // 그래프의 최대 깊이

bool connected[MAX_DEPTH + 1][MAX_DEPTH + 1] = { false, }; // 인접 행렬을 false로 초기화
bool visited[MAX_DEPTH + 1] = { false, }; // 방문 여부 배열을 false로 초기화

std::queue<int> q; // 방문할 노드를 예약하는 큐
int num, edge_num; // 노드의 수, 엣지의 수

/**
 * 너비우선탐색 방법으로 그래프를 순회하며 탐색한 노드들을 순서대로 하나씩 출력하는 함수
 * @param v 현재 탐색 중인 노드의 번호
 */
void bfs(int v)
{
	printf("%d\n", v); // 현재 노드를 출력
	q.push(v); // 현재 노드를 큐에 push
	visited[v] = true; // 현재 노드의 방문 여부를 true로 체크

	while (!q.empty()) // 아직 방문하지 않은 노드가 큐에 남아 있는 경우
	{
		// 큐에서 가장 앞에 있는 노드를 기준이 되는 노드로 설정하고 해당 노드를 큐에서 pop
		v = q.front();
		q.pop();

		// 연결된 노드들 중에서 아직 방문하지 않은 노드들을 일괄적으로 탐색
		for (int i = 1; i <= num; i++)
			if (connected[v][i] && !visited[i])
			{
				printf("%d\n", i); // 탐색 노드를 출력
				q.push(i); // 탐색 노드를 큐에 push
				visited[i] = true; // 탐색 노드의 방문 여부를 true로 체크
			}
	}
}

int main()
{
	scanf("%d %d", &num, &edge_num);

	for (int i = 0; i < edge_num; i++)
	{
		// 그래프 노드 간의 연결 상태를 입력 받은 뒤 인접 행렬에 반영
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		connected[v1][v2] = connected[v2][v1] = true;
	}

	bfs(1); // 1번 노드부터 탐색 시작

	return 0;
}