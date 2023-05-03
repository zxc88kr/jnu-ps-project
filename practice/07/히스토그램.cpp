// 문제해결프로젝트 실습 07 (3)
// 학번 : 195443
// 이름 : 박찬

#include <cstdio>
#include <vector>
#include <stack>

/**
 * 주어진 히스토그램 내부에서 가질 수 있는 가장 큰 직사각형의 넓이를 반환하는 함수
 * @param histograms 히스토그램의 높이 벡터 histograms[0] ~ histograms[n]
 * @param n			 히스토그램의 수
 * @return			 주어진 히스토그램 내부에서 가질 수 있는 가장 큰 직사각형의 넓이를 반환
 */
long long getMaxRectangleArea(std::vector<int>& histograms, int n)
{
	std::stack<int> stackHeight; // 히스토그램의 높이를 저장하는 스택
	std::stack<int> stackIndex; // 히스토그램의 인덱스 번호를 저장하는 스택

	// 가장 왼쪽에 히스토그램을 추가 (높이 0, 인덱스 번호 0)
	stackHeight.push(0);
	stackIndex.push(0);

	// 가장 오른쪽에 히스토그램을 추가 (높이 0, 인덱스 번호 n)
	histograms[n] = 0;

	long long maxRectangleArea = 0; // 주어진 히스토그램 내부에서 가질 수 있는 가장 큰 직사각형의 넓이

	for (int i = 0; i < n + 1; i++) // 모든 히스토그램을 대상으로 탐색
	{
		// 현재 히스토그램의 높이보다 높은 히스토그램들은 같은 직사각형이 되지 못하므로, 이에 해당하는 히스토그램들을 전부 스택에서 pop
		while (stackHeight.size() > 1 && stackHeight.top() > histograms[i])
		{
			int targetHistogramHeight = stackHeight.top(); // 직사각형을 이루는 히스토그램들 중 가장 오른쪽 히스토그램의 높이

			stackHeight.pop();
			stackIndex.pop();

			int targetHistogramIndex = stackIndex.top(); // 직사각형을 이루는 히스토그램들 바깥 바로 왼쪽 히스토그램의 인덱스 번호

			long long height = targetHistogramHeight;
			long long width = i - targetHistogramIndex;
			long long rectangleArea = height * width;

			maxRectangleArea = ((rectangleArea > maxRectangleArea) ? rectangleArea : maxRectangleArea);
		}
		stackHeight.push(histograms[i]); // 현재 히스토그램의 높이를 스택에 push
		stackIndex.push(i + 1); // 현재 히스토그램의 인덱스 번호를 스택에 push, 실제 인덱스는 1부터 시작
	}
	return maxRectangleArea;
}

int main()
{
	int t;
	scanf("%d", &t);

	for (int idx = 0; idx < t; idx++)
	{
		int n;
		scanf("%d", &n);

		std::vector<int> histograms(n + 1); // 가장 오른쪽에 히스토그램을 추가하기 위해 크기를 1 증가
		for (int i = 0; i < n; i++)
			scanf("%d", &histograms[i]);

		long long maxRectangleArea = getMaxRectangleArea(histograms, n);
		printf("%lld\n", maxRectangleArea);
	}

	return 0;
}