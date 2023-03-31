#include <cstdio>

const int MAX_TABLE_LENGTH = 10000;

void fillFrequencyTable(int data[], int n, int table[])
{
    for (int i = 0; i < MAX_TABLE_LENGTH; i++)
        table[i] = 0;
    for (int i = 0; i < n; i++)
        table[data[i]]++;
}

int getFrequentNumber(int data[], int n)
{
    int frequentNumber = 0;

    int table[MAX_TABLE_LENGTH];
    fillFrequencyTable(data, n, table);

    for (int i = 1; i < MAX_TABLE_LENGTH; i++)
        if (table[i] > table[frequentNumber])
            frequentNumber = i;
            
    return frequentNumber;
}

int main()
{
    int n;
    int* data;

    scanf("%d", &n);
    data = new int[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);

    int answer = getFrequentNumber(data, n);
    printf("%04d\n", answer);

    delete[] data;
    return 0;
}