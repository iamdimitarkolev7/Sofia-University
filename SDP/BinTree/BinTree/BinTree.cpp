#include <cassert>
#ifndef __BINTREE_CPP
#define __BINTREE_CPP

#include <iostream>

template <class T>
class BinTree
{
	struct Node
	{
		T data;
		Node* left, * right;
	};

	Node* root;

	Node* copyHelper(Node* node);
	void copy(const BinTree<T>& other);

	void clearHelper(Node* node);
	void clear();

	bool containsHelper(Node* node, const T& data);
	bool isEvenHelper(Node* node);
	bool hasRepeatedHelper(Node* node);
	T minHelper(Node* node);
	T maxHelper(Node* node);
	
public:
	BinTree();
	BinTree(const BinTree<T>& other);
	BinTree& operator=(const BinTree<T>& other);

	void push(const T& data, const char* path);
	bool contains(const T& data);
	bool isEven();
	bool hasRepeatedElements();
	//TODO bool hasWord(const char* word);
	T min();
	T max();
	
	~BinTree();

};

template <class T>
typename BinTree<T>::Node* BinTree<T>::copyHelper(Node* node)
{
	if (!node)
	{
		return nullptr;
	}

	Node* result = new Node();
	result->data = node->data;
	result->left = copyHelper(node->left);
	result->right = copyHelper(node->right);

	return result;
}

template <class T>
void BinTree<T>::copy(const BinTree<T>& other)
{
	root = copyHelper(other->root);
}

template <class T>
void BinTree<T>::clearHelper(Node* node)
{
	if (!node)
	{
		return;
	}

	clearHelper(node->left);
	clearHelper(node->right);

	delete node;
}

template <class T>
void BinTree<T>::clear()
{
	clearHelper(root);
}

template <class T>
bool BinTree<T>::containsHelper(Node* node, const T& data)
{
	if (node == nullptr)
	{
		return false;
	}
	
	return node->data == data ||
		containsHelper(node->left, data) ||
		containsHelper(node->right, data);
}

template <class T>
bool BinTree<T>::isEvenHelper(Node* node)
{
	if (node == nullptr)
	{
		return true;
	}

	return node->data % 2 == 0 &&
		isEvenHelper(node->left) &&
		isEvenHelper(node->right);
}

template <class T>
bool BinTree<T>::hasRepeatedHelper(Node* node)
{
	//TODO
	return true;
}

template <class T>
T BinTree<T>::minHelper(Node* node)
{
	if (node == nullptr)
	{
		return INT16_MAX;
	}

	T currentMin = node->data;
	T minLeft = minHelper(node->left);
	T minRight = minHelper(node->right);

	if (currentMin > minLeft)
	{
		currentMin = minLeft;
	}

	if (currentMin > minRight)
	{
		currentMin = minRight;
	}

	return currentMin;
}

template <class T>
T BinTree<T>::maxHelper(Node* node)
{
	if (node == nullptr)
	{
		return INT16_MIN;
	}

	T currentMax = node->data;
	T maxLeft = maxHelper(node->left);
	T maxRight = maxHelper(node->right);

	if (currentMax < maxLeft)
	{
		currentMax = maxLeft;
	}

	if (currentMax < maxRight)
	{
		currentMax = maxRight;
	}

	return currentMax;
}

template <class T>
BinTree<T>::BinTree():root(nullptr){}

template <class T>
BinTree<T>::BinTree(const BinTree<T>& other)
{
	copy(other);
}

template <class T>
BinTree<T>& BinTree<T>::operator=(const BinTree<T>& other)
{
	if (this != &other)
	{
		copy(other);
		clear();
	}

	return *this;
}

template <class T>
void BinTree<T>::push(const T& data, const char* path)
{
	if (root == nullptr)
	{
		if (path[0] == 0)
		{
			root = new Node{ data, nullptr, nullptr };
		}

		return;
	}

	if (path[0] == 0)
	{
		std::cout << "Invalid path!" << std::endl;
		return;
	}

	Node* current = root;

	while (path[1] != 0)
	{
		if (path[0] != 'R' && path[0] != 'L')
		{
			std::cout << "Path must contains only \'L\' and \'R\'" << std::endl;
			return;
		}

		if (path[0] == 'L')
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}

		if (current == nullptr)
		{
			std::cout << "Invalid path!" << std::endl;
			return;
		}

		path++;
	}

	if (path[0] == 'L' && current != nullptr && current->left == nullptr)
	{
		current->left = new Node{ data, nullptr, nullptr };
	}
	else if (path[0] == 'R' && current != nullptr && current->right == nullptr)
	{
		current->right = new Node{ data, nullptr, nullptr };
	}
	else
	{
		std::cout << "The place you want to assign the value must be empty!" << std::endl;
	}
}

template <class T>
bool BinTree<T>::contains(const T& data)
{
	return containsHelper(root, data);
}

template <class T>
bool BinTree<T>::isEven()
{
	return isEvenHelper(root);
}

template <class T>
bool BinTree<T>::hasRepeatedElements()
{
	return hasRepeatedHelper(root);
}

template <class T>
T BinTree<T>::min()
{
	return minHelper(root);
}

template <class T>
T BinTree<T>::max()
{
	return maxHelper(root);
}

template <class T>
BinTree<T>::~BinTree()
{
	clear();
}

#endif
