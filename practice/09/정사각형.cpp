// 문제해결프로젝트 실습 09 (2)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <cmath>
#include <vector>
#include <set>

// 한 점의 x 좌표와 y 좌표를 포함하는 구조체
struct Point2D
{
	int x; // 한 점의 x 좌표
	int y; // 한 점의 y 좌표

	// 생성자
	Point2D() : x(0), y(0) {}
	Point2D(int _x, int _y) : x(_x), y(_y) {}

	// 두 점 사이의 거리를 한 변으로 하는 정사각형의 넓이를 반환하는 메서드
	friend long long getSquaredDistanceTo(const Point2D& a, const Point2D& b)
	{
		long long dx = std::abs((long long)a.x - b.x);
		long long dy = std::abs((long long)a.y - b.y);
		return dx * dx + dy * dy;
	}

	// 연산자 오버로딩 (x 좌표와 y 좌표를 기준으로 대소비교, x좌표 -> y좌표 순서)
	friend bool operator<(const Point2D& a, const Point2D& b)
	{
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	}
	friend bool operator>(const Point2D& a, const Point2D& b)
	{
		if (a.x != b.x) return a.x > b.x;
		return a.y > b.y;
	}
};

/**
 * 주어진 점들 중 4개를 골라 만들 수 있는 정사각형의 가장 큰 넓이를 반환하는 함수
 * @param n      점의 좌표의 수
 * @param points 점 구조체 벡터 points[0] ~ points[n - 1]
 * @return       주어진 점들 중 4개를 골라 만들 수 있는 정사각형의 가장 큰 넓이를 반환
 */
long long getMaximumSquareArea(int n, std::vector<Point2D>& points)
{
	long long maximumSquareArea = 0; // 만들 수 있는 정사각형의 가장 큰 넓이를 0으로 초기화

	std::set<Point2D> pSet; // 사용자가 입력한 점의 좌표를 저장하는 Set
	for (int i = 0; i < n; i++)
		pSet.insert(points[i]); // Set에 사용자가 입력한 점의 좌표를 insert

	// 순서를 신경쓰는 임의의 두 점을 대상으로 탐색
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			// 임의의 두 점이 같은 점인 경우 continue
			if (i == j) continue;

			// 임의의 두 점을 선택
			Point2D pa = points[i];
			Point2D pb = points[j];

			// 두 점 사이의 거리를 한 변으로 하는 정사각형의 넓이를 구함
			long long squareArea = getSquaredDistanceTo(pa, pb);

			// 두 점 사이의 거리를 한 변으로 하는 정사각형의 넓이가 현재 가장 큰 넓이보다 작은 경우 continue
			if (squareArea < maximumSquareArea) continue;

			// 두 점을 기준으로 x 좌표의 차와 y 좌표의 차를 구함
			int dx = pb.x - pa.x;
			int dy = pb.y - pa.y;

			// 위에서 구한 좌표의 차를 이용하여 나머지 두 점의 좌표를 구함
			Point2D pc(pb.x + dy, pb.y - dx);
			Point2D pd(pa.x + dy, pa.y - dx);

			// 나머지 두 점의 좌표가 Set에 존재하는 경우, 현재 정사각형의 넓이를 기준으로 가장 큰 넓이를 업데이트
			if (pSet.count(pc) > 0 && pSet.count(pd) > 0)
				maximumSquareArea = ((squareArea > maximumSquareArea) ? squareArea : maximumSquareArea);
		}
	return maximumSquareArea;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int idx = 0; idx < t; idx++)
	{
		int n;
		scanf("%d", &n);

		std::vector<Point2D> points(n);
		for (int i = 0; i < n; i++)
		{
			// 입력받은 x 좌표 y 좌표를 이용하여 점 구조체 생성
			int x, y;
			scanf("%d %d", &x, &y);
			points[i] = Point2D(x, y);
		}

		double maximumSquareArea = (double)getMaximumSquareArea(n, points);
		printf("%.2lf\n", maximumSquareArea); // 출력 표시 형식에 따라 소수점 둘째 자리까지 표시
	}

	return 0;
}