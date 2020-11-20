#include <iostream>
#include <stack>
#include <string>

void fillStack(std::stack<char> &s, std::string src)
{
	for (size_t i = 0; i < src.length(); i++)
	{
		s.push(src[i]);
	}
}

bool isValid(std::stack<char> s)
{
	int openBracket1 = 0, closingBracket1 = 0;
	int openBracket2 = 0, closingBracket2 = 0;
	int openBracket3 = 0, closingBracket3 = 0;

	while (!s.empty())
	{
		switch(s.top())
		{
		case '(': openBracket1++;
			break;
		case ')': closingBracket1++;
			break;
		case '{': openBracket2++;
			break;
		case '}': closingBracket2++;
			break;
		case '[': openBracket3++;
			break;
		case ']': closingBracket3++;
			break;
		}

		s.pop();
	}

	return openBracket1 == closingBracket1 &&
		openBracket2 == closingBracket2 &&
		openBracket3 == closingBracket3;
}

int main()
{
    std::string str;
	std::cin >> str;

	std::stack<char> stack;
	fillStack(stack, str);
	isValid(stack) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

	return 0;
}