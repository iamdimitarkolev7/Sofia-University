#include <iostream>
#include <stack>

int height(std::stack<int> stack)
{
	int result = 0;

	while (!stack.empty())
	{
		result += stack.top();
		stack.pop();
	}

	return result;
}

int largestHeight(std::stack<int> stack1, std::stack<int> stack2, std::stack<int> stack3)
{
	while (height(stack1) != height(stack2) || height(stack2) != height(stack3) || height(stack1) != height(stack3))
	{
		if (height(stack1) > height(stack2) || height(stack1) > height(stack3))
			stack1.pop();
		else if (height(stack2) > height(stack1) || height(stack2) > height(stack3))
			stack2.pop();
		else if (height(stack3) > height(stack1) || height(stack3) > height(stack2))
			stack3.pop();
	}

	return height(stack1);
}

int main()
{
	std::stack<int> stack1, stack2, stack3;
	
	stack1.push(2); stack1.push(1); stack1.push(1); stack1.push(1); stack1.push(1);
	stack2.push(4); //stack2.push(3); stack2.push(4);
	stack3.push(1); stack3.push(4); //stack3.push(1); stack3.push(1);

	std::cout << largestHeight(stack1, stack2, stack3) << std::endl;

    return 0;
}
