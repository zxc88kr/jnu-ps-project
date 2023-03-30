#include <cstdio>

const int MAX_COLOR_NUMBER = 100;

void fillFrequencyTable(int seat[], int n, int table[])
{
    for (int i = 0; i < MAX_COLOR_NUMBER; i++)
        table[i] = 0;
    for (int i = 0; i < n; i++)
        table[seat[i]]++;
}

void solve(int seat[], int n)
{
    int minColor = -1;
    int maxColor = -1;

    int table[MAX_COLOR_NUMBER];
    fillFrequencyTable(seat, n, table);

    for (int i = 0; i < MAX_COLOR_NUMBER; i++)
    {
        if (table[i] == 0) continue;

        if (minColor == -1 && maxColor == -1)
        {
            minColor = i;
            maxColor = i;
        }
        else if (table[i] < table[minColor])
            minColor = i;
        else if (table[i] > table[maxColor])
            maxColor = i;
    }

    printf("%d\n", maxColor);
    printf("%d\n", minColor);
}

int main()
{
    int n, m;
    int* seat;

    scanf("%d %d", &n, &m);
    seat = new int[n];
    for (int i = 0; i < n; i++)
        seat[i] = 0;

    for (int i = 0; i < m; i++)
    {
        int begin, end, color;
        scanf("%d %d %d", &begin, &end, &color);

        for (int idx = begin; idx <= end; idx++)
            seat[idx - 1] = color;
    }

    solve(seat, n);

    delete[] seat;
    return 0;
}