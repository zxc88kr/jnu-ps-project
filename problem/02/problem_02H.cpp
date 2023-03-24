#include <cstdio>

bool isInside(long long x, long long y, long long r)
{
	long long distSquare = (x * x) + (y * y);
	long long rSquare = (r * r);

	if (distSquare < rSquare) return true;
	return false;
}

long long getPixelInsideOfRound(long long r)
{
	long long pixelSum = 0;
	long long y = r;

	for (long long x = 0; x <= r; x++)
		for (; y >= 0; y--)
			if (isInside(x, y, r))
			{
				pixelSum += (y + 1);
				break;
			}

	pixelSum *= 4;
	return pixelSum;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int idx = 0; idx < t; idx++)
	{
		long long r;
		scanf("%lld", &r);

		long long pixel = getPixelInsideOfRound(r);

		printf("#%d\n", idx + 1);
		printf("%lld\n", pixel);
	}

	return 0;
}