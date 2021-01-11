#include <iostream>

struct Node
{
	char data;
	Node* left, * right;
};

bool match_word(const Node* node, const char* str)
{
	if (node == nullptr)
	{
		return false;
	}

	if (node->left == nullptr && node->right == nullptr && str[1] == '\0')
	{
		return node->data == str[0];
	}

	if (node->data != str[0])
	{
		return false;
	}

	return match_word(node->left, ++str) || match_word(node->right, ++str);
}

bool has_word(const Node* node, const char* str)
{
	if (node == nullptr)
	{
		return false;
	}

	bool is_current_match = false;

	if (str[0] == node->data)
	{
		is_current_match = match_word(node, str);
	}

	return is_current_match || has_word(node->left, str) || has_word(node->right, str);
}

void print2DUtil(const Node* root, int space)
{
	if (root == nullptr)
		return;

	space += 3;

	print2DUtil(root->right, space);

	std::cout << std::endl;
	for (int i = 3; i < space; i++)
		std::cout << " ";
	std::cout << root->data << "\n";

	print2DUtil(root->left, space);
}

void print2D(const Node* root)
{
	print2DUtil(root, 0);
}

int main()
{
	const Node* root =
		new Node{ 'a',
			new Node{'b',
				new Node{'r', nullptr, nullptr},
				nullptr},
			new Node{'c',
				new Node{'p', nullptr, nullptr},
				new Node{'l',
					new Node{'o', nullptr, nullptr},
					nullptr}} };

	std::cout << has_word(root, "acp") << std::endl;

	print2D(root);
	
	return 0;
}