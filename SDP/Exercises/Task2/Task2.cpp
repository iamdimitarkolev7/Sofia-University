#include <iostream>

template <class T>
struct Node
{
	T data;
	Node* left, *right;
};

template <class T>
T sum_even(const Node<T>* node, int crrLevel)
{
	if (node == nullptr)
	{
		return 0;
	}

	if (crrLevel % 2 == 0)
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			return node->data + sum_even(node->left, crrLevel + 1) + sum_even(node->left, crrLevel + 1);
		}
	}

	return sum_even(node->left, crrLevel + 1) + sum_even(node->right, crrLevel + 1);
}

template <class T>
T product_odd(const Node<T>* node, int crrLevel)
{
	if (node == nullptr)
	{
		return 1;
	}

	if (crrLevel % 2 != 0)
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			return node->data * product_odd(node->left, crrLevel + 1) * product_odd(node->left, crrLevel + 1);
		}
	}

	return product_odd(node->left, crrLevel + 1) * product_odd(node->right, crrLevel + 1);
}

template <class T>
bool is_symmetric_helper(const Node<T>* node1, const Node<T>* node2)
{
	if (node1 == nullptr && node2 == nullptr) return true;
	if (node1 == nullptr || node2 == nullptr) return false;

	return is_symmetric_helper(node1->left, node2->right) && is_symmetric_helper(node1->right, node2->left);
}

template <class T>
bool is_symmetric(const Node<T>* node)
{
	return is_symmetric_helper(node->left, node->right);
}

template <class T>
bool is_symmetric_value_helper(const Node<T>* node1, const Node<T>* node2)
{
	if (node1 == nullptr && node2 == nullptr)
	{
		return true;
	}

	if (node1 && node2 && node1->data == node2->data)
	{
		return is_symmetric_value_helper(node1->left, node2->right) &&
			is_symmetric_value_helper(node1->right, node2->left);
	}

	return false;
}

template <class T>
bool is_symmetric_value(const Node<T>* node)
{
	return is_symmetric_value_helper(node, node);
}

template <class T>
Node<T>* sumTrees(const Node<T>* node1, const Node<T>* node2)
{
	if (node1 == nullptr && node2 == nullptr)
	{
		return nullptr;
	}
	if (node1 != nullptr && node2 == nullptr)
	{
		return new Node<T>{ node1->data, sumTrees(node1->left, node2), sumTrees(node1->right, node2)  };
	}
	if (node1 == nullptr && node2 != nullptr)
	{
		return new Node<T>{ node2->data, sumTrees(node1, node2->left), sumTrees(node1, node2->right) };
	}
	if (node1 && node2)
	{
		return new Node<T>{ node1->data + node2->data, sumTrees(node1->left, node2->left), sumTrees(node1->right, node2->right) };
	}
}

template <class T>
void print(const Node<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	print(node->left);
	std::cout << node->data << " ";
	print(node->right);
}

void print2DUtil(const Node<int>* root, int space)
{
	if (root == nullptr)
		return;
 
	space += 5;
	
	print2DUtil(root->right, space);

	std::cout << std::endl;
	for (int i = 5; i < space; i++)
		std::cout << " ";
	std::cout << root->data << "\n";

	print2DUtil(root->left, space);
}

void print2D(const Node<int>* root)
{
	print2DUtil(root, 0);
}

int main()
{
	const Node<int>* root =
		new Node<int>{ 1,
			new Node<int>{2,
				new Node<int>{3,
					nullptr,
					nullptr},
				new Node<int>{4,
					nullptr,
					nullptr}},
			new Node<int>{ 2,
				new Node<int>{4,
					nullptr,
					nullptr},
				new Node<int>{3,
					nullptr,
					nullptr}} };

	const Node<int>* anotherRoot =
		new Node<int>{ 5,
			new Node<int>{4,
				nullptr,
				new Node<int>{3,
					nullptr,
					nullptr}},
			new Node<int>{8,
				new Node<int>{6,
					nullptr,
					nullptr},
				nullptr}};

	const Node<int>* resultRoot = sumTrees<int>(root, anotherRoot);

	print2D(resultRoot);
	std::cout << std::endl;

	const std::pair<int, int> result = std::make_pair(sum_even<int>(root, 0), product_odd<int>(root, 0));

	std::cout << "Sum: " << result.first << std::endl << "Product: " << result.second << std::endl;

	if (is_symmetric<int>(root))
	{
		std::cout << "The tree is symmetric" << std::endl;
	}
	else
	{
		std::cout << "The tree is not symmetric" << std::endl;
	}

	if (is_symmetric_value<int>(root))
	{
		std::cout << "The tree is symmetric by its values" << std::endl;
	}
	else
	{
		std::cout << "The tree is not symmetric by its values" << std::endl;
	}
	
    return 0;
}