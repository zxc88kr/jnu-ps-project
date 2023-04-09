// 문제해결프로젝트 실습 05 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

/**
 * 주어진 칸의 인덱스가 위치한 행 번호를 반환하는 함수
 * @param index 대상이 되는 인덱스
 * @return 		주어진 칸의 인덱스가 위치한 행 번호를 반환
 */
int getRowByIndex(int index)
{
	return (index - 1) / 9 + 1;
}

/**
 * 주어진 칸의 인덱스가 위치한 열 번호를 반환하는 함수
 * @param index 대상이 되는 인덱스
 * @return 		주어진 칸의 인덱스가 위치한 열 번호를 반환
 */
int getColByIndex(int index)
{
	return (index - 1) % 9 + 1;
}

/**
 * 주어진 칸의 위치가 속한 그룹 번호를 반환하는 함수
 * @param row 대상이 되는 행 번호
 * @param col 대상이 되는 열 번호
 * @return 	  주어진 칸의 위치가 속한 그룹 번호를 반환
 */
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

    for (int idx = 1; idx <= t; idx++) // 테스트 케이스 번호는 1부터 시작
    {
        int index;
        scanf("%d", &index);

		int row = getRowByIndex(index); // 행 번호
		int col = getColByIndex(index); // 열 번호
		int group = getGroupByPosition(row, col); // 그룹 번호

		printf("Case #%d:\n", idx);
		printf("%d %d %d\n", row, col, group);
    }
	
    return 0;
}