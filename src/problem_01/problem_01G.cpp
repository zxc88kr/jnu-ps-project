#include <cstdio>
#include <string>

void printIndexes(std::string school[], int n)
{
	int first = -1, last = -1;
	for (int i = 0; i < n; i++)
		if (school[i] == "AJOU")
		{
			if (first == -1) first = i + 1;
			last = i + 1;
		}

	printf("%d %d\n", first, last);
}

int main()
{
	int n;
	char buff[11];
	std::string* school;

	scanf("%d", &n);
	school = new std::string[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", buff);
		school[i] = buff;
	}
	
	printIndexes(school, n);

	delete[] school;
	return 0;
}