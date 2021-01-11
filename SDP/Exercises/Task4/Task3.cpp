#include <iostream>

struct Node
{
	char data;
	Node* left, * right;
};

bool match(const Node* node, const char* str)
{
	if (node == nullptr)
	{
		return false;
	}

	if (node->left != nullptr && node->left->data == str[1])
	{
		return match(node->left, ++str);
	}

	if (node->right != nullptr && node->right->data == str[1])
	{
		return match(node->right, ++str);
	}

	if (str[1] == '\0')
	{
		return node->data == str[0];
	}

	return false;
}

bool has_word(const Node* node, const char* str)
{
	if (node == nullptr)
	{
		return false;
	}

	bool currentMatch = false;
	
	if (node->data == str[0])
	{
		currentMatch = match(node, str);
	}

	return currentMatch || has_word(node->left, str) || has_word(node->right, str);
}

int count_word_occurrence(const Node* node, const char* word)
{
	if (node == nullptr)
	{
		return 0;
	}

	if (match(node, word))
	{
		return 1 + count_word_occurrence(node->left, word) + count_word_occurrence(node->right, word);
	}

	return count_word_occurrence(node->left, word) + count_word_occurrence(node->right, word);
}

void print2D(const Node* node, int space)
{
	if (node == nullptr)
	{
		return;
	}

	space += 3;

	print2D(node->right, space);

	std::cout << std::endl;

	for (int i = 3; i < space; ++i)
	{
		std::cout << " ";
	}
	
	std::cout << node->data << std::endl;
	
	print2D(node->left, space);
}

int main()
{
	const Node* root =
		new Node{ 'm',
			new Node{'o',
				new Node{'m',
					nullptr,
					new Node{'o', nullptr, nullptr}}},
			new Node{'o',
				new Node{'m',
					new Node{'o', nullptr, nullptr},
					new Node{'o', nullptr, nullptr}},
				new Node{'m', nullptr, nullptr}} };

	std::cout << has_word(root, "momo") << std:: endl;
	std::cout << count_word_occurrence(root, "o") << std::endl;
	print2D(root, 0);
	return 0;
}