#include <cstdio>
#include <vector>

std::vector<int> getTicketNumbers(int n, int m, std::vector<int>& ids)
{
    std::vector<int> tickets;
    std::vector<bool> given(n);

    for (int i = 0; i < m; i++)
    {
        int index = ids[i] % n;
        while (given[index])
            index = (index + 1) % n;

        given[index] = true;
        tickets.push_back(index);
    }
    return tickets;
}

int main()
{
	int n, m;
    scanf("%d %d", &n, &m);

	std::vector<int> ids(m);
	for (int i = 0; i < m; i++)
		scanf("%d", &ids[i]);

	std::vector<int> tickets = getTicketNumbers(n, m, ids);
    for (int i = 0; i < tickets.size(); i++)
        printf("%d\n", tickets[i]);

    return 0;
}