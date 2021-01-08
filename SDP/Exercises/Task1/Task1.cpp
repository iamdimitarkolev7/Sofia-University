#include <iostream>

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

int main()
{
	Node* root = new Node{ 1,
		new Node{2,
			new Node{4,
				new Node{5, nullptr, nullptr},
				nullptr},
			nullptr},
		new Node{3,
			new Node{7,
				new Node{8, nullptr, nullptr},
				nullptr},
		nullptr} };

	std::cout << sum(root, 0) << std::endl;

	return 0;
}