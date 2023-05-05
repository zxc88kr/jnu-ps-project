#include <cstdio>
#include <vector>
#include <queue>

struct City
{
    int index;
    int income;

    City() : index(-1), income(-1) {}
    City(int idx, int incm) : index(idx), income(incm) {}

    bool operator<(const City& city) const
    {
        return this->income < city.income;
    }
    bool operator>(const City& city) const
    {
        return this->income > city.income;
    }
};

int getMaxDifferenceInRange(std::vector<City>& cities, int n, int k)
{
    int maxDifference = 0;

    std::priority_queue<City, std::vector<City>, std::less<City>> maximumInRange;
    std::priority_queue<City, std::vector<City>, std::greater<City>> minimumInRange;

    for (int i = 0; i < k - 1; i++)
    {
        maximumInRange.push(cities[i]);
        minimumInRange.push(cities[i]);
    }
    for (int i = k - 1; i < n; i++)
    {
        maximumInRange.push(cities[i]);
        minimumInRange.push(cities[i]);
        while (maximumInRange.top().index < i - (k - 1)) maximumInRange.pop();
        while (minimumInRange.top().index < i - (k - 1)) minimumInRange.pop();

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
            int income;
            scanf("%d", &income);
            cities[i] = City(i, income);
        }
        int maxDifference = getMaxDifferenceInRange(cities, n, k);
        printf("%d\n", maxDifference);
	}

    return 0;
}