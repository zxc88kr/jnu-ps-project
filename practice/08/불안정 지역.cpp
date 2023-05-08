// 문제해결프로젝트 실습 08 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <vector>
#include <queue>

// 도시의 인덱스와 소득 수준을 포함하는 구조체
struct City
{
    int index; // 도시의 인덱스
    int income; // 도시의 소득 수준

    // 생성자
    City() : index(-1), income(-1) {}
    City(int idx, int incm) : index(idx), income(incm) {}

    // 연산자 오버로딩 (소득 수준을 기준으로 대소비교)
    bool operator<(const City& city) const
    {
        return this->income < city.income;
    }
    bool operator>(const City& city) const
    {
        return this->income > city.income;
    }
};

/**
 * 연속한 k개의 도시로 이루어진 영역들 중 가장 큰 소득차를 반환하는 함수
 * @param cities 도시 구조체 벡터 cities[0] ~ cities[n - 1]
 * @param n      도시의 수
 * @param k      연속한 도시의 수
 * @return       연속한 k개의 도시로 이루어진 영역들 중 가장 큰 소득차를 반환
 */
int getMaxDifferenceInRange(std::vector<City>& cities, int n, int k)
{
    int maxDifference = 0; // 가장 큰 소득차

    // 소득이 가장 높은 도시부터 pop되는 우선순위 큐
    std::priority_queue<City, std::vector<City>, std::less<City>> maximumInRange;
    // 소득이 가장 낮은 도시부터 pop되는 우선순위 큐
    std::priority_queue<City, std::vector<City>, std::greater<City>> minimumInRange;

    for (int i = 0; i < k - 1; i++) // k - 1 개의 도시 구조체를 우선순위 큐에 push
    {
        maximumInRange.push(cities[i]);
        minimumInRange.push(cities[i]);
    }
    for (int i = k - 1; i < n; i++) // 나머지 도시 구조체를 정해진 규칙에 따라 우선순위 큐에 push
    {
        maximumInRange.push(cities[i]);
        minimumInRange.push(cities[i]);

        // 최대, 최소 소득을 가진 도시가 검사 범위 밖에 있다면, 이에 해당하는 도시들을 전부 우선순위 큐에서 pop
        while (maximumInRange.top().index < i - (k - 1)) maximumInRange.pop();
        while (minimumInRange.top().index < i - (k - 1)) minimumInRange.pop();

        // 현재 영역에서의 소득차를 기준으로 가장 큰 소득차를 업데이트
        int difference = maximumInRange.top().income - minimumInRange.top().income;
        maxDifference = ((difference > maxDifference) ? difference : maxDifference);
    }
    return maxDifference;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int idx = 0; idx < t; idx++)
	{
		int n, k;
		scanf("%d %d", &n, &k);

        std::vector<City> cities(n);
        for (int i = 0; i < n; i++)
        {
            // 입력받은 소득 수준을 이용하여 0번째 도시 구조체부터 생성
            int income;
            scanf("%d", &income);
            cities[i] = City(i, income);
        }
        int maxDifference = getMaxDifferenceInRange(cities, n, k);
        printf("%d\n", maxDifference);
	}

    return 0;
}