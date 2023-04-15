// 문제해결프로젝트 실습 06 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <algorithm>

/**
 * 주어진 두 직사각형이 교차하는 영역의 넓이를 반환하는 함수
 * @param lA 첫 번째 직사각형의 왼쪽 변
 * @param rA 첫 번째 직사각형의 오른쪽 변
 * @param bA 첫 번째 직사각형의 아래쪽 변
 * @param tA 첫 번째 직사각형의 위쪽 변
 * @param lB 두 번째 직사각형의 왼쪽 변
 * @param rB 두 번째 직사각형의 오른쪽 변
 * @param bB 두 번째 직사각형의 아래쪽 변
 * @param tB 두 번째 직사각형의 위쪽 변
 * @return   주어진 두 직사각형이 교차하는 영역의 넓이를 반환
 */
int getOverlapArea(int lA, int rA, int bA, int tA, int lB, int rB, int bB, int tB)
{
    int l, r, b, t; // 교차하는 직사각형의 네 변의 좌표
    l = std::max(lA, lB); // 교차하는 직사각형의 왼쪽 변
    r = std::min(rA, rB); // 교차하는 직사각형의 오른쪽 변
    b = std::max(bA, bB); // 교차하는 직사각형의 아래쪽 변
    t = std::min(tA, tB); // 교차하는 직사각형의 위쪽 변

    if (l < r && b < t) // 모든 변의 길이는 0 이상
        return (r - l) * (t - b); // 교차하는 직사각형의 넓이
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int ax, ay, bx, by; // 첫 번째 직사각형의 네 점의 좌표
        int px, py, qx, qy; // 두 번째 직사각형의 네 점의 좌표
        scanf("%d %d %d %d", &ax, &ay, &bx, &by);
        scanf("%d %d %d %d", &px, &py, &qx, &qy);

        int lA, rA, bA, tA; // 첫 번째 직사각형의 네 변의 좌표
        lA = std::min(ax, bx); // 첫 번째 직사각형의 왼쪽 변
        rA = std::max(ax, bx); // 첫 번째 직사각형의 오른쪽 변
        bA = std::min(ay, by); // 첫 번째 직사각형의 아래쪽 변
        tA = std::max(ay, by); // 첫 번째 직사각형의 위쪽 변

        int lB, rB, bB, tB; // 두 번째 직사각형의 네 변의 좌표
        lB = std::min(px, qx); // 두 번째 직사각형의 왼쪽 변
        rB = std::max(px, qx); // 두 번째 직사각형의 오른쪽 변
        bB = std::min(py, qy); // 두 번째 직사각형의 아래쪽 변
        tB = std::max(py, qy); // 두 번째 직사각형의 위쪽 변

        int answer = getOverlapArea(lA, rA, bA, tA, lB, rB, bB, tB); // 두 직사각형이 교차하는 영역의 넓이
        printf("%d\n", answer);
    }
    
    return 0;
}