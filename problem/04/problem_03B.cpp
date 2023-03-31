// 문제해결프로젝트 실습 04 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

const int MAX_COLOR_NUMBER = 100; // 빈도수 테이블의 최대 크기 0 ~ 99

/**
 * 주어진 배열로부터 각각의 색상에 대한 빈도수 테이블을 생성하는 함수
 * @param seat  좌석에 칠해진 색상 배열 seat[0] ~ seat[n - 1]
 * @param n     배열의 크기
 * @param table 각각의 색상에 대한 빈도수 테이블 table[0] ~ table[99]
 */
void fillFrequencyTable(int seat[], int n, int table[])
{
    for (int i = 0; i < MAX_COLOR_NUMBER; i++)
        table[i] = 0; // 빈도수 테이블의 값을 전부 0으로 초기화
    for (int i = 0; i < n; i++)
        table[seat[i]]++; // 등장한 색상의 빈도수를 각각 1씩 증가
}

/**
 * 주어진 배열에서 가장 많이 등장한 색상과 가장 적게 등장한 색상을 출력하는 함수
 * @param seat 좌석에 칠해진 색상 배열 seat[0] ~ seat[n - 1]
 * @param n    배열의 크기
 */
void solve(int seat[], int n)
{
    int minColor = -1; // 가장 적게 등장한 색상을 -1로 초기화
    int maxColor = -1; // 가장 많이 등장한 색상을 -1로 초기화

    int table[MAX_COLOR_NUMBER];
    fillFrequencyTable(seat, n, table);

    for (int i = 0; i < MAX_COLOR_NUMBER; i++)
    {
        if (table[i] == 0) continue; // 어떠한 좌석에도 칠해져 있지 않은 색상은 스킵

        if (minColor == -1 && maxColor == -1) // 처음 등장한 색상으로 주어진 변수들을 초기화
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
        seat[i] = 0; // 처음에 모든 좌석은 0번 색상으로 칠해져 있음

    for (int i = 0; i < m; i++)
    {
        int begin, end, color;
        scanf("%d %d %d", &begin, &end, &color);

        // begin 부터 end 까지의 좌석을 color 색상으로 칠함
        for (int idx = begin; idx <= end; idx++)
            seat[idx - 1] = color; // 실제 인덱스는 0부터 시작
    }

    solve(seat, n);

    delete[] seat;
    return 0;
}