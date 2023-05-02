#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool isValidPS(std::string str)
{
	std::stack<bool> st;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') st.push(true);
		else if (str[i] == ')')
		{
			if (st.size() > 0) st.pop();
			else return false;
		}
	}
	if (st.size() == 0) return true;
	else return false;
}

int main()
{
	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++)
	{
		std::string str;
		std::cin >> str;
		
		if (isValidPS(str)) std::cout << "YES\n";
		else				std::cout << "NO\n";
	}

	return 0;
}