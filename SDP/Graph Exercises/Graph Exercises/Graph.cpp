#include "Graph.h"

void Graph::init()
{
	std::cout << "Insert vertex count: ";
	std::cin >> numberOfVertecies;
	graph = new std::vector<int>[numberOfVertecies];
	used = new bool[numberOfVertecies];
	std::fill_n(used, numberOfVertecies, false);

	int numberOfEdges;
	std::cout << "Insert edges count: ";
	std::cin >> numberOfEdges;

	for (int i = 0; i < numberOfEdges; i++)
	{
		int n, m;
		std::cin >> n >> m;
		graph[n].push_back(m);
		graph[m].push_back(n);
	}
}

void Graph::clear()
{
	delete[] graph;
	delete[] used;
}

Graph::Graph()
{
	init();
}

Graph::~Graph()
{
	clear();
}

void Graph::BFS(int start)
{
	std::queue<int> q;
	q.push(start);
	used[start] = true;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();
		std::cout << current << " ";

		for (int i = 0; i < graph[current].size(); i++)
		{
			if (!used[graph[current][i]])
			{
				q.push(graph[current][i]);
				used[graph[current][i]] = true;
			}
		}
	}
}

void Graph::DFS(int start)
{
	used[start] = true;
	
	std::cout << start << " ";
	
	for (int i = 0; i < graph[start].size(); i++)
	{
		if (!used[graph[start][i]])
		{
			DFS(graph[start][i]);
		}
	}
}

int Graph::shortestPathBetween(int A, int B)
{
	int result = 0;
	std::queue<int> q;
	q.push(A);
	used[A] = true;
	q.push(-1);

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		if (curr == B)
		{
			return result;
		}

		if (curr == -1)
		{
			if (q.empty())
			{
				return result;
			}

			q.push(-1);
			result++;
		}
		else
		{
			for (int i = 0; i < graph[curr].size(); i++)
			{
				if (!used[graph[curr][i]])
				{
					used[graph[curr][i]] = true;
					q.push(graph[curr][i]);
				}
			}
		}
	}

	//In case there is no way from A to B
	return INT16_MIN;
}

int Graph::longestPathBetween(int A, int B)
{
	if (A == B)
	{
		return 1;
	}

	used[A] = true;
	int maxLength = 0;

	for (int i = 0; i < graph[A].size(); i++)
	{
		if (!used[graph[A][i]])
		{
			int pathLength = longestPathBetween(graph[A][i], B);
			maxLength = std::max(maxLength, pathLength);
		}
	}

	used[A] = false;

	return maxLength == 0 ? 0 : maxLength + 1;
}