#include <cstdio>
#include <algorithm>

int getOverlapArea(int lA, int rA, int bA, int tA, int lB, int rB, int bB, int tB)
{
    int l, r, b, t;
    l = std::max(lA, lB);
    r = std::min(rA, rB);
    b = std::max(bA, bB);
    t = std::min(tA, tB);

    if (l <= r && b <= t)
        return (r - l) * (t - b);
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int ax, ay, bx, by;
        int px, py, qx, qy;
        scanf("%d %d %d %d", &ax, &ay, &bx, &by);
        scanf("%d %d %d %d", &px, &py, &qx, &qy);

        int lA, rA, bA, tA;
        lA = std::min(ax, bx);
        rA = std::max(ax, bx);
        bA = std::min(ay, by);
        tA = std::max(ay, by);

        int lB, rB, bB, tB;
        lB = std::min(px, qx);
        rB = std::max(px, qx);
        bB = std::min(py, qy);
        tB = std::max(py, qy);

        int answer = getOverlapArea(lA, rA, bA, tA, lB, rB, bB, tB);
        printf("%d\n", answer);
    }

    return 0;
}