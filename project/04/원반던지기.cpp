// 문제해결프로젝트 프로젝트 04 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio> // 표준 입출력 라이브러리
#include <vector> // 벡터 라이브러리
#include <utility> // 개체 쌍 라이브러리
#include <stack> // 스택 라이브러리
#include <ctime> // 시간 라이브러리

/**
 * 원반을 던질 수 있는 소가 있는 모든 위치 쌍의 거리의 합을 반환하는 함수
 * @param cows  소 pair 벡터 cows[0] ~ cows[n - 1]
 * @param n     원반을 던질 수 있는 소들의 수
 * @return      원반을 던질 수 있는 소가 있는 모든 위치 쌍의 거리의 합을 반환
 */
long long getSumFrisbeeDistance(std::vector<std::pair<int, int>>& cows, int n)
{
    std::stack<std::pair<int, int>> stackCow; // 소의 pair를 저장하는 스택

    long long sumFrisbeeDistance = 0; // 모든 위치 쌍의 거리의 합을 0으로 초기화

    for (int i = 0; i < n; i++) // 소가 서 있는 순으로 탐색
    {
        while (!stackCow.empty()) // 스택에 값이 존재하는 경우
        {
            // 스택의 탑에 있는 소와 현재 탐색 중인 소 사이의 거리를 계산
            sumFrisbeeDistance += (cows[i].second - stackCow.top().second + 1);

            // 현재 탐색 중인 소의 키가 스택의 탑에 있는 소의 키보다 큰 경우
            // 스택의 탑을 하나 pop하고 반복문을 다시 진행
            // 그게 아니라면, 반복문을 종료하고 빠져나옴
            // 스택의 탑에 있는 소를 i, 현재 탐색 중인 소를 j라고 했을 때,
            // 스택의 탑을 pop 한다는 의미는 새로운 i가 정의되고,
            // 기존의 i는 새로운 i와 j 사이에 위치한 소가 되므로,
            // 기존의 i의 키 < j의 키인 경우, 원반 던지기가 가능하지만,
            // 그 반대의 경우, 원반 던지기가 불가능
            if (stackCow.top().first < cows[i].first) stackCow.pop();
            else break;
        }
        stackCow.push(cows[i]); // 현재 탐색 중인 소의 pair를 스택에 push
    }
    return sumFrisbeeDistance;
}

int main()
{
    int n;
    scanf("%d", &n);

    std::vector<std::pair<int, int>> cows(n);
    for (int i = 0; i < n; i++)
    {
        // 입력받은 소의 키를 이용하여 pair 생성
        scanf("%d", &cows[i].first);
        cows[i].second = i + 1; // 실제 인덱스는 1부터 시작
    }

    clock_t start = clock(); // 시간 측정 시작

    long long sumFrisbeeDistance = getSumFrisbeeDistance(cows, n);
    printf("%lld\n", sumFrisbeeDistance);

    clock_t end = clock(); // 시간 측정 종료

    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}