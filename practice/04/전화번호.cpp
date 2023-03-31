// 문제해결프로젝트 실습 04 (1)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

const int MAX_TABLE_LENGTH = 10000; // 빈도수 테이블의 최대 크기 0000 ~ 9999

/**
 * 주어진 배열로부터 각각의 번호에 대한 빈도수 테이블을 생성하는 함수
 * @param data  네 자리 전화번호 배열 data[0] ~ data[n - 1]
 * @param n     배열의 크기
 * @param table 각각의 번호에 대한 빈도수 테이블 table[0] ~ table[9999]
 */
void fillFrequencyTable(int data[], int n, int table[])
{
    for (int i = 0; i < MAX_TABLE_LENGTH; i++)
        table[i] = 0; // 빈도수 테이블의 값을 전부 0으로 초기화
    for (int i = 0; i < n; i++)
        table[data[i]]++; // 등장한 번호의 빈도수를 각각 1씩 증가
}

/**
 * 주어진 배열에서 가장 많이 등장한 번호를 반환하는 함수
 * @param data 네 자리 전화번호 배열 data[0] ~ data[n - 1]
 * @param n    배열의 크기
 * @return     주어진 배열에서 가장 많이 등장한 번호를 반환
 */
int getFrequentNumber(int data[], int n)
{
    int frequentNumber = 0; // 가장 많이 등장한 번호를 0으로 초기화

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
    printf("%04d\n", answer); // 전화번호 뒷자리는 0을 포함한 네 자리 자연수

    delete[] data;
    return 0;
}