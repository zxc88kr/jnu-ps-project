#include <cstdio>
#include <map>

int main()
{
	int n;
	scanf("%d", &n);

	std::map<int, int> frequencyMap;
	
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);

		frequencyMap[num]++;
		printf("%d %d\n", frequencyMap.size(), frequencyMap[num]);
	}

	return 0;
}