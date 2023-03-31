// 문제해결프로젝트 실습 04 (3)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <vector>

const int MAX_SERIAL_NUMBER = 100000; // 빈도수 테이블의 최대 크기 0 ~ 99999

/**
 * 주어진 배열로부터 각각의 번호에 대한 빈도수 테이블을 생성하는 함수
 * @param data  시리얼 번호 배열 data[0] ~ data[n - 1]
 * @param n     배열의 크기
 * @param table 각각의 번호에 대한 빈도수 테이블 table[0] ~ table[99999]
 */
void fillFrequencyTable(const std::vector<int>& data, int n, std::vector<int>& table)
{
    table.clear();
    table.resize(MAX_SERIAL_NUMBER + 1, 0); // 실제 번호는 1부터 시작하므로 사이즈를 1 증가 table[0] ~ table[100000]
                                            // 빈도수 테이블의 값을 전부 0으로 초기화

    for (int i = 0; i < n; i++)
        table[data[i]]++; // 등장한 번호의 빈도수를 각각 1씩 증가
}

/**
 * 주어진 배열의 중복을 제거하고 오름차순으로 정렬한 뒤, 그 배열을 반환하는 함수
 * @param data 시리얼 번호 배열 data[0] ~ data[n - 1]
 * @param n    배열의 크기
 * @return     주어진 배열의 중복을 제거하고 오름차순으로 정렬한 뒤, 그 배열을 반환
 */
std::vector<int> getUniqueElements(const std::vector<int>& data, int n)
{
    std::vector<int> answer;

    std::vector<int> table;
    fillFrequencyTable(data, n, table);

    for (int i = 1; i <= MAX_SERIAL_NUMBER; i++)
        if (table[i] == 1) // 테이블에서 한 번만 등장한 경우
            answer.push_back(i); // 중복 없는 배열에 원소 추가

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
        if (i > 0) printf(" "); // 각 데이터는 공백으로 구분
        printf("%d", answer[i]);
    }
    printf("\n");

    return 0;
}