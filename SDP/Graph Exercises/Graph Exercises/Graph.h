#pragma once
#include <vector>
#include <queue>
#include <iostream>

class Graph
{
private:
	int numberOfVertecies;
	std::vector<int>* graph;
	bool* used;

	void init();
	void clear();
	
public:
	Graph();
	~Graph();

	void BFS(int start);
	void DFS(int start);
	int shortestPathBetween(int A, int B);
	int longestPathBetween(int A, int B);
};

