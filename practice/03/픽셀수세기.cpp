// 문제해결프로젝트 실습 03 (4)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>

/**
 * 주어진 좌표가 반지름이 r인 원 내부에 있는지 확인하는 함수
 * @param x 대상이 되는 x좌표
 * @param y 대상이 되는 y좌표
 * @param r 원의 반지름
 * @return 	주어진 좌표가 반지름이 r인 원 내부에 있으면 true, 그렇지 않으면 false를 반환
 */
bool isInside(long long x, long long y, long long r)
{
	long long distSquare = (x * x) + (y * y);
	long long rSquare = (r * r);

	if (distSquare < rSquare) return true; // x^2 + y^2 < r^2 이면, (x, y)는 원 내부에 있음
	return false;
}

/**
 * 반지름이 r인 원이 포함하고 있는 픽셀의 수를 반환하는 함수
 * @param r 원의 반지름
 * @return 	반지름이 r인 원이 포함하고 있는 픽셀의 수를 반환
 */
long long getPixelInsideOfRound(long long r)
{
	long long pixelSum = 0; // 픽셀의 총합, 1사분면의 픽셀을 구한 다음 4를 곱하여 전체 픽셀의 수를 구함
	long long y = r; // y좌표를 원의 가장 끝인 r로 초기화

	for (long long x = 0; x <= r; x++)
		for (; y >= 0; y--) // 반복문을 빠져나온 뒤 다시 실행할 때 y를 초기화 하지 않고, 이전 y값을 이어 받음
			if (isInside(x, y, r))
			{
				pixelSum += (y + 1); // 왼쪽 아래의 좌표가 원 내부에 있으면, 현재 x좌표의 픽셀 수는 (y + 1)
				break;
			}

	pixelSum *= 4;
	return pixelSum;
}

int main()
{
	int t; // 테스트 케이스 횟수
	scanf("%d", &t);

	for (int idx = 0; idx < t; idx++)
	{
		long long r;
		scanf("%lld", &r);

		long long pixel = getPixelInsideOfRound(r);

		printf("#%d\n", idx + 1); // 실제 번호는 1부터 시작
		printf("%lld\n", pixel);
	}

	return 0;
}