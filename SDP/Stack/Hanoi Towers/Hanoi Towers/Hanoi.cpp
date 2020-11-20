#include <iostream>
#include <stack>
#include <vector>

void transferDiscHanoi(std::stack<int>& A, std::stack<int>& B, std::stack<int>& C, char from, char to)
{
	if (from == 'A')
	{
		if (to == 'B')
		{
			B.push(A.top());
			A.pop();
		}
		if (to == 'C')
		{
			C.push(A.top());
			A.pop();
		}
	}

	if (from == 'B')
	{
		if (to == 'A')
		{
			A.push(B.top());
			B.pop();
		}
		if (to == 'C')
		{
			C.push(B.top());
			B.pop();
		}
	}

	if (from == 'C')
	{
		if (to == 'A')
		{
			A.push(C.top());
			C.pop();
		}
		if (to == 'B')
		{
			B.push(C.top());
			C.pop();
		}
	}
}

void printHanoi(std::stack<int> A, std::stack<int> B, std::stack<int> C)
{
	
}

void playHanoi(int k, char start, char dest, char temp, std::stack<int>& A, std::stack<int>& B, std::stack<int>& C)
{	
	if (k == 1)
	{
		std::cout << "Moving disc 1 from " << start << " to " << dest << std::endl;
		transferDiscHanoi(A, B, C, start, dest);
		printHanoi(A, B, C);
		return;
	}

	playHanoi(k - 1, start, temp, dest, A, B, C);
	//playHanoi(1, start, dest, temp, A, B, C);
	std::cout << "Moving disc " << k << " from " << start << " to " << dest << std::endl;
	transferDiscHanoi(A, B, C, start, dest);
	printHanoi(A, B, C);
	playHanoi(k - 1, temp, dest, start, A, B, C);
}

int main()
{
	std::stack<int> A, B, C;
	int k, discs;
	std::cout << "Insert number of discs: ";
	std::cin >> k;
	discs = k;

	while (discs > 0)
	{
		A.push(discs--);
	}
	
	playHanoi(k, 'A', 'C', 'B', A, B, C);

	return 0;
}