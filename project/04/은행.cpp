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

    for (int waiting = t - 1; waiting >= 0; waiting--) // 최대 대기 시간이 가장 긴 고객부터 탐색
    {
        // 우선순위 큐에 아직 push 되지 않은 고객이 남아 있는 경우
        // 현재 탐색하고 있는 최대 대기 시간에 해당하는 고객의 금액을 전부 우선순위 큐에 push
        while (idx < n && customers[idx].first == waiting)
        {
            availableAmount.push(customers[idx].second);
            idx++;
        }

        // 우선순위 큐에 값이 존재하는 경우
        // 우선순위 큐에서 가장 큰 금액 하나만을 처리하고, 해당 금액을 우선순위 큐에서 pop
        // 최대 대기 시간이 짧은 고객을 우선적으로 처리하는 것이 아니라, 기회비용까지 종합적으로 계산하여 고객을 처리
        if (!availableAmount.empty())
        {
            maximumAmount += availableAmount.top();
            availableAmount.pop();
        }
    }
    return maximumAmount;

	// 예시 (n = 3, t = 4, 입력은 (1000 0), (2000 1), (500 1) 이라고 가정)
    // 사용자 정의 함수에 의해, 입력은 (1 2000), (1 500), (0 1000) 순으로 정렬됨
	// (첫 번째 반복문: t = 3) -> 아무 일도 일어나지 않음
	// (두 번째 반복문: t = 2) -> 아무 일도 일어나지 않음
	// (세 번째 반복문: t = 1) -> 우선순위 큐에 (2000), (500) 순으로 push -> 우선순위 큐에서 가장 큰 (2000) pop -> 우선순위 큐에 (500) 존재
	// (네 번째 반복문: t = 0) -> 우선순위 큐에 (1000) push -> 우선순위 큐에서 가장 큰 (1000) pop -> 우선순위 큐에 (500) 존재
	// 반복문 종료: maximumAmount = 2000 + 1000 = 3000
}

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);

    std::vector<std::pair<int, int>> customers(n);
    for (int i = 0; i < n; i++) // 최대 대기 시간을 first, 금액을 second로 입력 받음
        scanf("%d %d", &customers[i].second, &customers[i].first);

    clock_t start = clock(); // 시간 측정 시작
    
    // 최대 대기 시간을 기준으로 내림차순 정렬, 최대 대기 시간이 같다면 금액을 기준으로 내림차순 정렬
    std::sort(customers.begin(), customers.end(), compareCustomer);

    int maximumAmount = getMaximumAmount(customers, n, t);
    printf("%d\n", maximumAmount);

    clock_t end = clock(); // 시간 측정 종료

    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}