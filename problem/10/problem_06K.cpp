#include <iostream>
#include <string>
#include <map>

int main()
{
	int n;
	std::cin >> n;

	std::map<std::string, int> frequencyMap;
	int maxFrequency = 0;

	for (int i = 0; i < n; i++)
	{
		std::string str;
		std::cin >> str;

		frequencyMap[str]++;
		int frequency = frequencyMap[str];
		maxFrequency = ((frequency > maxFrequency) ? frequency : maxFrequency);
	}

	std::cout << maxFrequency << '\n';
	for (auto it = frequencyMap.begin(); it != frequencyMap.end(); it++)
		if (it->second == maxFrequency)
			std::cout << it->first.c_str() << ' ';
	std::cout << '\n';

	return 0;
}