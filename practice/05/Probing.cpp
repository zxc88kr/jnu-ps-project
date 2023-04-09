// 문제해결프로젝트 실습 05 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <vector>

/**
 * 회원 번호를 기준으로 행운권을 지급하였을 때, 지급받게 될 행운권 번호 벡터를 반환하는 함수
 * @param n   행운권 번호의 수
 * @param m   회원의 수
 * @param ids 회원 번호 벡터 ids[0] ~ ids[n - 1]
 * @return    회원 번호를 기준으로 행운권을 지급하였을 때, 지급받게 될 행운권 번호 벡터를 반환
 */
std::vector<int> getTicketNumbers(int n, int m, std::vector<int>& ids)
{
    std::vector<int> tickets; // 지급받게 될 행운권 번호 벡터
    std::vector<bool> used(n); // 행운권 번호 사용 여부 벡터

    for (int i = 0; i < m; i++)
    {
        int index = ids[i] % n; // 회원 번호를 n으로 나눈 나머지
        while (used[index]) // 해당 행운권 번호가 사용된 행운권 번호인 경우
            index = (index + 1) % n; // 사용되지 않은 번호를 찾을 때까지 행운권 번호를 1씩 증가시키면서 선형 조사

        used[index] = true; // 해당 행운권 번호가 사용되었음을 체크
        tickets.push_back(index); // 행운권 번호 벡터에 해당 행운권 번호를 추가
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