// 문제해결프로젝트 실습 08 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <vector>
#include <queue>

/**
 * 각 번호의 사람들이 정해진 규칙대로 게임을 진행했을 때 게임에서 제외되는 사람 순서 벡터를 반환하는 함수
 * @param n 게임에 참여하는 사람의 수
 * @param m 게임 규칙 (m 번째 사람을 반복적으로 제외)
 * @return  각 번호의 사람들이 정해진 규칙대로 게임을 진행했을 때 게임에서 제외되는 사람 순서 벡터를 반환
 */
std::vector<int> getDeadPlayers(int n, int m)
{
    std::vector<int> deadPlayers; // 게임에서 제외되는 사람 순서 벡터

    std::queue<int> players; // 아직 게임에서 제외되지 않은 사람 큐
    for (int i = 0; i < n; i++) // 1 ~ n 번째 사람이 게임에 참여
        players.push(i + 1);

    for (int i = 0; i < n; i++) // 모든 사람이 게임에서 제외될 때까지 게임을 진행
    {
        int skip = m - 1; // m - 1 명의 사람을 건너뛰고 그 다음 사람을 게임에서 제외시킴

        // 건너뛴 사람의 경우 큐에서 pop 한 다음, 큐의 마지막 대기열로 다시 push
        while (skip > 0)
        {
            int skipPlayer = players.front();
            players.pop();
            players.push(skipPlayer);
            skip--;
        }

        // 제외되는 사람의 경우 큐에서 pop 한 다음, 제외되는 사람 순서 벡터에 push
        int deadPlayer = players.front();
        players.pop();
        deadPlayers.push_back(deadPlayer);
    }
    return deadPlayers;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int idx = 0; idx < t; idx++)
	{
		int n, m;
		scanf("%d %d", &n, &m);

        std::vector<int> deadPlayers = getDeadPlayers(n, m);

        for (int i = 0; i < deadPlayers.size(); i++)
        {
            if (i > 0) printf(" "); // 각 데이터는 공백으로 구분
            printf("%d", deadPlayers[i]);
        }
        printf("\n");
	}

    return 0;
}