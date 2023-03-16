#include <iostream>
#include <string>

int getComparison(std::string s1, std::string s2)
{
	int order = 0;
	int len = 0;

	int len1 = s1.length();
	int len2 = s2.length();
	len = len1 < len2 ? len1 : len2;

	if (len1 == len2)	  order = 0;
	else if (len1 < len2) order = -1;
	else if (len1 > len2) order = 1;

	for (int i = 0; i < len; i++)
	{
		if (s1[i] == s2[i]) continue;
		else if (s1[i] < s2[i])
		{
			order = -1;
			break;
		}
		else if (s1[i] > s2[i])
		{
			order = 1;
			break;
		}
	}
	return order;
}

int main()
{
	std::string s1;
	std::string s2;
	std::cin >> s1 >> s2;

	int answer = getComparison(s1, s2);
	std::cout << answer << '\n';

	return 0;
}