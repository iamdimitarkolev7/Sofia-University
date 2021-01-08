#include <iostream>
#include <queue>
#include <vector>

std::vector<bool> used;

void add_edge(std::vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void print_graph(std::vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
	    std::cout << "\n Adjacency list of vertex "
            << v << "\n head ";

    	for (int x : adj[v])
	        std::cout << "-> " << x;

    	std::cout << std::endl;
    }
}

void bfs(int u)
{
	
}

int main()
{
	const int vertecies = 7;
	std::vector<int> graph[vertecies];

	add_edge(graph, 0, 1);
	add_edge(graph, 0, 4);
	add_edge(graph, 1, 3);
	add_edge(graph, 1, 6);
	add_edge(graph, 2, 3);
	add_edge(graph, 3, 4);
	add_edge(graph, 4, 5);
	add_edge(graph, 5, 6);
	print_graph(graph, vertecies);

	return 0;
}