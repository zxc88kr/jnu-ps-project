#include <cstdio>
#include <set>

int main()
{
	int n;
	scanf("%d", &n);

	std::set<int> s;
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);

		if (s.count(num) > 0)
			printf("DUPLICATED\n");
		else
		{
			s.insert(num);
			printf("OK\n");
		}
	}

	return 0;
}