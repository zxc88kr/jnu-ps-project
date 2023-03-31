#include <cstdio>
#include <vector>

const int MAX_SERIAL_NUMBER = 100000;

void fillFrequencyTable(const std::vector<int>& data, int n, std::vector<int>& table)
{
    table.clear();
    table.resize(MAX_SERIAL_NUMBER + 1, 0);

    for (int i = 0; i < n; i++)
        table[data[i]]++;
}

std::vector<int> getUniqueElements(const std::vector<int>& data, int n)
{
    std::vector<int> answer;

    std::vector<int> table;
    fillFrequencyTable(data, n, table);

    for (int i = 1; i <= MAX_SERIAL_NUMBER; i++)
        if (table[i] == 1)
            answer.push_back(i);

    return answer;
}

int main()
{
    int n;
    scanf("%d", &n);

    std::vector<int> data(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);

    const std::vector<int> answer = getUniqueElements(data, n);

    for (int i = 0; i < answer.size(); i++)
    {
        if (i > 0) printf(" ");
        printf("%d", answer[i]);
    }
    printf("\n");

    return 0;
}