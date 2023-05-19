// 문제해결프로젝트 프로젝트 04 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio> // 표준 입출력 라이브러리
#include <vector> // 벡터 라이브러리
#include <utility> // 개체 쌍 라이브러리
#include <queue> // 큐 라이브러리
#include <algorithm> // 알고리즘 라이브러리
#include <ctime> // 시간 라이브러리

/**
 * pair 벡터를 정렬하기 위해 사용되는 사용자 정의 함수
 * @param a 첫 번째 pair
 * @param b 두 번째 pair
 * @return  first 값을 기준으로 내림차순 정렬, first 값이 같다면 second 값을 기준으로 내림차순 정렬
 */
bool compareCustomer(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

/**
 * 은행 문을 닫기 전, 대기열에 있는 고객들로부터 받을 수 있는 최대 금액을 반환하는 함수
 * @param customers 고객 pair 벡터 customers[0] ~ customers[n - 1]
 * @param n         대기열에 있는 고객들의 수
 * @param t         은행 문을 닫을 때까지의 시간
 * @return          은행 문을 닫기 전, 대기열에 있는 고객들로부터 받을 수 있는 최대 금액을 반환
 */
int getMaximumAmount(std::vector<std::pair<int, int>>& customers, int n, int t)
{
    // 가장 큰 금액부터 pop되는 우선순위 큐
    std::priority_queue<int, std::vector<int>, std::less<int>> availableAmount;

    int maximumAmount = 0; // 받을 수 있는 최대 금액을 0으로 초기화
    int idx = 0; // 우선순위 큐에 고객의 금액을 하나 push 할 때마다 idx 값을 1씩 증가

    for (int waiting = t - 1; waiting >= 0; waiting--) // 대기 시간이 가장 많이 남아 있는 고객부터 탐색
    {
        // 우선순위 큐에 push 되지 않은 고객이 아직 남아 있는 경우
        // 현재 탐색하고 있는 대기 시간에 해당하는 고객의 금액을 전부 push
        while (idx < n && customers[idx].first == waiting)
        {
            availableAmount.push(customers[idx].second);
            idx++;
        }

        // 우선순위 큐에 값이 존재하는 경우
        // 우선순위 큐에서 금액이 가장 큰 고객 한 명만을 처리하고, 해당하는 금액을 우선순위 큐에서 pop
        if (!availableAmount.empty())
        {
            maximumAmount += availableAmount.top();
            availableAmount.pop();
        }
    }
    return maximumAmount;
}

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);

    std::vector<std::pair<int, int>> customers(n);
    for (int i = 0; i < n; i++) // 대기 시간을 first, 금액을 second로 입력 받음
        scanf("%d %d", &customers[i].second, &customers[i].first);

    clock_t start = clock(); // 시간 측정 시작
    
    // 대기 시간을 기준으로 내림차순 정렬, 대기 시간이 같다면 금액을 기준으로 내림차순 정렬
    std::sort(customers.begin(), customers.end(), compareCustomer);

    int maximumAmount = getMaximumAmount(customers, n, t);
    printf("%d\n", maximumAmount);

    clock_t end = clock(); // 시간 측정 종료

    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}