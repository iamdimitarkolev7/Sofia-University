#include <iostream>
#include <stack>

struct GameGoal
{
	int k;
	char start, dest, temp;
};

void playHanoiIter(int k, char start, char dest, char temp)
{
	std::stack<GameGoal> s;

	s.push({ k, start, dest, temp });

	while (!s.empty())
	{
		GameGoal current = s.top(); s.pop();

		if (current.k == 1)
		{
			std::cout << "Please move a disc from " << current.start << " to " << current.dest << std::endl;
		}
		else
		{
			s.push({ current.k - 1, current.temp, current.dest, current.start });
			s.push({ 1, current.start, current.dest, current.temp });
			s.push({ current.k - 1, current.start, current.temp, current.dest });
		}
	}
}

int main()
{
	playHanoiIter(3, 'A', 'C', 'B');

	return 0;
}