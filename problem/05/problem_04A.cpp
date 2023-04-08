#include <cstdio>

int getRowByIndex(int index)
{
	return (index - 1) / 9 + 1;
}

int getColByIndex(int index)
{
	return (index - 1) % 9 + 1;
}

int getGroupByPosition(int row, int col)
{
	int base = ((row - 1) / 3) * 3 + 1;
	int offset = (col - 1) / 3;
	return base + offset;
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int idx = 1; idx <= t; idx++)
    {
        int index;
        scanf("%d", &index);

		int row = getRowByIndex(index);
		int col = getColByIndex(index);
		int group = getGroupByPosition(row, col);

		printf("Case #%d:\n", idx);
		printf("%d %d %d\n", row, col, group);
    }

    return 0;
}