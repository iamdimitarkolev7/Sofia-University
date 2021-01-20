#include <iostream>
#include <queue>

struct Node
{
	int data;
	Node* left, * right;
};

void BFS(Node* node)
{
	if (node == nullptr)
	{
		return;
	}

	std::queue<Node*> q;
	q.push(node);

	while (!q.empty())
	{
		Node* crr = q.front();
		q.pop();
		std::cout << crr->data << " ";

		if (crr->left != nullptr)
		{
			q.push(crr->left);
		}
		
		if (crr->right != nullptr)
		{
			q.push(crr->right);
		}
	}
}

void print_level(Node* node, int level)
{
	if (node == nullptr)
	{
		return;
	}

	if (level == 0)
	{
		std::cout << node->data << " ";
	}
	else
	{
		print_level(node->left, level - 1);
		print_level(node->right, level - 1);
	}
}

void print2D(Node* node, int space)
{
	if (node == nullptr)
	{
		return;
	}

	space += 5;

	
	print2D(node->right, space);
	for (int i = 5; i < space; i++)
		std::cout << " ";
	std::cout << node->data << std::endl;

	print2D(node->left, space);
}

int main()
{
	Node* root =
		new Node{ 1,
			new Node{2,
				new Node{4, nullptr, nullptr},
				nullptr},
			new Node{3,
				new Node{5, nullptr, nullptr},
				new Node{6, nullptr, nullptr}} };

	print_level(root, 1);
	std::cout << std::endl;

	BFS(root);

	std::cout << std::endl;

	print2D(root, 0);

	return 0;
}