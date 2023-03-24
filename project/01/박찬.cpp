// 문제해결프로젝트 프로젝트 01
// 학번 : 195443
// 이름 : 박찬

#include <cstdio> // 표준 입출력 라이브러리
#include <ctime> // 시간 라이브러리

/**
 * 빠진 페이지를 인쇄하기 위해 필요한 잉크의 양을 반환하는 함수
 * @param page 논문의 각 페이지 장수 page[0] ~ page[n - 1]
 * @param n    논문의 마지막 페이지 번호
 * @return     빠진 페이지를 인쇄하기 위해 필요한 잉크의 양을 반환
 */
int solve(int page[], int n)
{
    int inkSum = 0; // 필요한 잉크의 총합
    int skip = 3; // 현재 페이지 이전에 인쇄하지 않고 넘어간 페이지 수
                  // 최소 한 번 이상은 (5 + 2K) 만큼의 잉크를 사용하여 인쇄하므로, 반복문 조건에 따라 3으로 초기화

    for (int i = 0; i < n; i++) // 논문의 첫 페이지부터 마지막 페이지까지 각 페이지 장수를 탐색
    {
        if (page[i] == 0) // 빠진 페이지를 발견할 경우, 현재 페이지를 인쇄
        {
            inkSum += 2; // 각 페이지를 인쇄하기 위해 기본적으로 2의 잉크가 필요
            if (skip >= 3) inkSum += 5; // skip이 3 이상이면, 새로운 인쇄 목록을 생성하는 것이 좋음
                                        // 새로운 인쇄 목록으로 현재 페이지를 인쇄하므로, 5의 잉크가 추가적으로 필요
            else inkSum += skip * 2; // skip이 3 미만이면, 기존의 인쇄 목록을 유지하는 것이 좋음
                                     // 연속성을 유지하기 위해 이미 존재하는 페이지를 추가 인쇄하므로, (skip * 2)의 잉크가 추가적으로 필요
                                     // (각 페이지를 인쇄하기 위해 기본적으로 2의 잉크가 필요)
            skip = 0; // 현재 페이지를 인쇄하였으므로, skip을 0으로 리셋

            // "."은 빠진 페이지를 의미
            // (1 . 3 -> 5 + 2 + 5 + 2 = 14) > (1 2 3 -> 5 + 6 = 11) -> skip이 1일 경우, 기존의 인쇄 목록을 유지하는 것이 좋음
            // (1 . . 4 -> 5 + 2 + 5 + 2 = 14) > (1 2 3 4 -> 5 + 8 = 13) -> skip이 2일 경우, 기존의 인쇄 목록을 유지하는 것이 좋음
            // (1 . . . 5 -> 5 + 2 + 5 + 2 = 14) < (1 2 3 4 5 -> 5 + 10 = 15) -> skip이 3일 경우, 새로운 인쇄 목록을 생성하는 것이 좋음
        }
        else skip++; // 이미 존재하는 페이지를 발견할 경우, skip을 1 증가
    }
    return inkSum; // 필요한 잉크의 총합을 리턴
}

int main()
{
    int n, m; // n: 논문의 마지막 페이지 번호, m: 바닥에 흩어진 논문의 페이지 장수
    int* page; // 논문의 각 페이지 장수를 저장하는 배열
    int* scattered; // 바닥에 흩어진 논문의 페이지 번호를 저장하는 배열

    scanf("%d %d", &n, &m);
    page = new int[n];
    scattered = new int[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &scattered[i]);

    clock_t start = clock(); // 시간 측정 시작

    for (int i = 0; i < n; i++)
        page[i] = 0; // 각 페이지 장수를 0으로 초기화
    for (int i = 0; i < m; i++)
        page[scattered[i] - 1]++; // 바닥에 흩어진 논문의 페이지 번호에 해당하는 page 배열의 값을 1 증가
                                  // 실제 배열의 인덱스는 0부터 시작

    int ink = solve(page, n);
    printf("%d\n", ink);

    clock_t end = clock(); // 시간 측정 종료

    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

    delete[] page;
    delete[] scattered;
    return 0;
}