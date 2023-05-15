#include <cstdio>
#include <cmath>
#include <vector>
#include <set>

struct Point2D
{
	int x;
	int y;

	Point2D() : x(0), y(0) {}
	Point2D(int _x, int _y) : x(_x), y(_y) {}

	friend long long getSquaredDistanceTo(const Point2D& a, const Point2D& b)
	{
		long long dx = std::abs((long long)a.x - b.x);
		long long dy = std::abs((long long)a.y - b.y);
		return dx * dx + dy * dy;
	}

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

long long getMaximumSquareArea(int n, std::vector<Point2D>& points)
{
	long long maximumSquareArea = 0;

	std::set<Point2D> pSet;
	for (int i = 0; i < n; i++)
		pSet.insert(points[i]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;

			Point2D pa = points[i];
			Point2D pb = points[j];

			long long squareArea = getSquaredDistanceTo(pa, pb);

			if (squareArea < maximumSquareArea) continue;

			int dx = pb.x - pa.x;
			int dy = pb.y - pa.y;

			Point2D pc(pb.x + dy, pb.y - dx);
			Point2D pd(pa.x + dy, pa.y - dx);

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
			int x, y;
			scanf("%d %d", &x, &y);
			points[i] = Point2D(x, y);
		}

		double maximumSquareArea = (double)getMaximumSquareArea(n, points);
		printf("%.2lf\n", maximumSquareArea);
	}

	return 0;
}