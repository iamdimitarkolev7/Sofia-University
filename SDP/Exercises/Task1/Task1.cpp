#include <iostream>
#include <queue>

struct Node
{
	int data;
	Node* left, * right;
};

int sum(Node* node, int crrLevel = 0)
{
	if (node == nullptr)
	{
		return 0;
	}

	const int crrElement = node->data;

	if (crrLevel % 2 == 0)
	{
		if (node->left != nullptr && node->right == nullptr)
		{
			return crrElement + sum(node->left, crrLevel + 1) + sum(node->right, crrLevel + 1);
		}
	}

	return sum(node->left, crrLevel + 1) + sum(node->right, crrLevel + 1);

}

void printLevel(Node* node, int level)
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
		printLevel(node->left, level - 1);
		printLevel(node->right, level - 1);
	}
}

void clear(Node*& node)
{
	if (node == nullptr)
	{
		return;
	}

	clear(node->left);
	clear(node->right);

	delete node;
	node = nullptr;
}

int main()
{
	Node* root =
	new Node{ 1,
		new Node{2,
			new Node{4,
				new Node{5, nullptr, nullptr},
				new Node{6, nullptr, nullptr}},
			nullptr},
		new Node{3,
			new Node{7,
				new Node{8, nullptr, nullptr},
				nullptr},
		nullptr} };

	printLevel(root, 3);

	clear(root);

	return 0;
}