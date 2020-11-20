#include <iostream>
#include <stack>

bool isCorrect(const char* tag)
{
	std::stack<char> stack;

	while (tag[0] != '\0')
	{
		if (tag[0] == '<')
		{
			tag++;
			if (tag[0] == '/')
			{
				tag++;
				if (tag[0] == stack.top() && stack.size() > 0)
					stack.pop();
				else
					return false;
			}
			else
				stack.push(tag[0]);
		}
		tag++;
	}

	return stack.size() == 0;
}

int main()
{
	std::cout << isCorrect("<f>lorem<m>ips/umf</m>dolor</f>") << std::endl;
	std::cout << isCorrect("<f>lorem<m>ipsum</f>dolor</m>") << std::endl;

	return 0;
}