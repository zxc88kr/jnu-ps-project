// 문제해결프로젝트 실습 06 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <vector>
#include <algorithm>

/**
 * 중복을 포함한 세 카드의 합으로 만들 수 있는 당첨번호 벡터를 반환하는 함수
 * @param n       카드의 수
 * @param m       당첨번호의 수
 * @param cards   카드 벡터 cards[0] ~ cards[n - 1]
 * @param targets 당첨번호 벡터 targets[0] ~ targets[m - 1]
 * @return        중복을 포함한 세 카드의 합으로 만들 수 있는 당첨번호 벡터를 반환
 */
std::vector<int> getPossibleTargets(int n, int m, std::vector<int>& cards, std::vector<int>& targets)
{
    std::vector<int> possibleTargets; // 만들 수 있는 당첨번호 벡터

    std::sort(cards.begin(), cards.end()); // 모든 카드를 오름차순으로 정렬

    for (int idx = 0; idx < m; idx++) // 모든 당첨번호를 대상으로 탐색
    {
        int target = targets[idx]; // 타겟이 되는 당첨번호
        bool possible = false; // 중복을 포함한 세 카드의 합으로 타겟을 만들 수 있는지 확인, 초기값은 false

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                int x = cards[i]; // 첫 번째 카드
                int y = cards[j]; // 두 번째 카드
                int z = target - x - y; // 세 번째 카드

                // z가 card에서 발견되는 경우 x + y + z == target
                if (std::binary_search(cards.begin(), cards.end(), z))
                {
                    possible = true; // 타겟을 만들 수 있으면 첫 번째 반복문까지 빠져나옴
                    break;
                }
            }
            if (possible) break;
        }
        if (possible) possibleTargets.push_back(target); // 타겟을 결과 벡터에 추가
    }
    std::sort(possibleTargets.begin(), possibleTargets.end()); // 결과 벡터를 오름차순으로 정렬

    return possibleTargets;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    std::vector<int> cards(n);
    std::vector<int> targets(m);

    for (int i = 0; i < n; i++)
        scanf("%d", &cards[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &targets[i]);

    std::vector<int> answers = getPossibleTargets(n, m, cards, targets);

    if (answers.size() > 0) // 결과벡터가 존재하는 경우
    {
        for (int i = 0; i < answers.size(); i++)
        {
            if (i > 0) printf(" "); // 각 데이터는 공백으로 구분
            printf("%d", answers[i]);
        }
        printf("\n");
    }
    else printf("NO\n"); // 결과벡터가 존재하지 않는 경우

    return 0;
}