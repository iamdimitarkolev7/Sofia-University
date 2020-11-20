#include <iostream>
#include <stack>
#include <string>

void reverse(std::string& str)
{
	std::stack<char> stack;
	
	for (char& i : str)
	{
		stack.push(i);
	}

	while (!stack.empty())
	{
		std::cout << stack.top();
		stack.pop();
	}
	
	std::cout << std::endl;
}

int main()
{
	std::string str;
	std::cin >> str;
	reverse(str);

	return 0;
}