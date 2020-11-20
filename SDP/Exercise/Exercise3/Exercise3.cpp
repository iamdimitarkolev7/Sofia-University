#include <iostream>
#include <string>
#include <stack>

bool isVariable(char symbol)
{
	return symbol >= 'a' && symbol <= 'z';
}

bool valid(const std::string& s, unsigned& error)
{
	if (s.size() == 1)
		return isVariable(s[0]);

	if (!isVariable(s[0]))
	{
		error = 0;
		return false;
	}
	
	std::stack<char> stack;
	
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == ',')
		{
			if (!isVariable(s[i + 1]))
			{
				error = i;
				return false;
			}
		}

		if (s[i] == '(')
		{
			if (isVariable(s[i + 1]))
			{
				stack.push('(');
			}
			else
			{
				error = i + 1;
				return false;
			}
		}
		
		if (s[i] == ')')
		{
			if (!stack.empty() && stack.top() == '(')
				stack.pop();
			else
			{
				error = i;
				return false;
			}
		}

		if (isVariable(s[i]))
		{
			if (isVariable(s[i + 1]))
			{
				error = i + 1;
				return false;
			}
		}
	}

	if (!stack.empty())
		error = s.size() - 1;

	return stack.empty();
}

int main()
{
	unsigned error = 0;
	std::cout << valid("f(g(x,y),h(k(u)),v)", error) << std::endl;
	std::cout << "Error Index: " << error << std::endl;
	std::cout << valid("f(g(x,x)", error) << std::endl;
	std::cout << "Error Index: " << error << std::endl;
	
	return 0;
}