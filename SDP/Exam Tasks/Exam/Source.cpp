#include <iostream>
#include <queue>
#include <vector>

struct Node
{
	int data;
	Node* left, * right;
};

struct CharNode
{
	char data;
	CharNode* left, * right;
};

void print(CharNode* node, int space)
{
	if (node == nullptr)
	{
		return;
	}

	space += 5;

	print(node->right, space);
	std::cout << std::endl;
	for (int i = 5; i < space; i++)
		std::cout << " ";
	std::cout << node->data;
	print(node->left, space);
}

//Task 1: max path
int maxpath(Node *t)
{
	if (t->left == nullptr && t->right == nullptr)
	{
		return t->data;
	}

	if (t->left != nullptr && t->right != nullptr)
	{
		if (t->left->data > t->data && t->right->data < t->left->data)
		{
			return t->data + maxpath(t->left);
		}
		if (t->right->data > t->data && t->right->data > t->left->data)
		{
			return t->data + maxpath(t->right);
		}
	}

	if (t->left != nullptr)
	{
		if (t->left->data > t->data)
		{
			return t->data + maxpath(t->left);
		}
		else
		{
			throw std::logic_error("There is no such path");
		}
	}

	if (t->right != nullptr)
	{
		if (t->right->data > t->data)
		{
			return t->data + maxpath(t->right);
		}
		else
		{
			throw std::logic_error("There is no such path");
		}
	}

	throw std::logic_error("There is no such path");
}

//Task 2: average the tree
//This is a helper function that gets tree height
int height(Node* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	std::queue<Node*> q;
	q.push(node);
	q.push(nullptr);

	int result = 1;

	while (!q.empty())
	{
		Node* crr = q.front();
		q.pop();

		if (crr == nullptr)
		{
			q.push(nullptr);
			if (q.front() == nullptr)
			{
				return result;
			}
			result++;
		}
		else
		{
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

	return result;
}

//Helper function which gets all node's data from a particular level
void get_level(Node* node, int level, std::vector<int>& result)
{
	if (node == nullptr)
	{
		return;
	}

	if (level == 0)
	{
		result.push_back(node->data);
	}

	get_level(node->left, level - 1, result);
	get_level(node->right, level - 1, result);
}
 
int get_average(std::vector<int> v)
{
	if (v.empty())
	{
		return 0;
	}
	
	int sum = 0;

	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}

	return sum / v.size();
}

//Task 2 function
std::vector<int> average(Node* node)
{
	std::vector<int> result;

	int h = height(node);

	for (int i = 0; i < h; i++)
	{
		std::vector<int> avg;
		get_level(node, i, avg);
		int res = get_average(avg);
		result.push_back(res);
	}

	return result;
}

//Task 3: find word occurrence
int height_charnode(CharNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	std::queue<CharNode*> q;
	q.push(node);
	q.push(nullptr);

	int result = 1;

	while (!q.empty())
	{
		CharNode* crr = q.front();
		q.pop();

		if (crr == nullptr)
		{
			q.push(nullptr);
			if (q.front() == nullptr)
			{
				return result;
			}
			result++;
		}
		else
		{
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

	return result;
}

void get_level_charnode(CharNode* node, int level, std::vector<char>& res)
{
	if (node == nullptr)
	{
		return;
	}

	if (level == 0)
	{
		res.push_back(node->data);
	}

	get_level_charnode(node->left, level - 1, res);
	get_level_charnode(node->right, level - 1, res);
}

bool vector_matches_word(std::vector<char> v, const char* word)
{
	if (v.size() != strlen(word))
	{
		return false;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != word[0])
			return false;

		word++;
	}

	return true;
}

int count_word_occurrence_root_to_leaf(CharNode* node, const char* word)
{
	if (node == nullptr)
	{
		return 0;
	}

	if (node->left == nullptr && node->right == nullptr && word[1] == '\0')
	{
		return node->data == word[0];
	}

	if (node->data == word[0])
	{
		word++;
		return count_word_occurrence_root_to_leaf(node->left, word) + count_word_occurrence_root_to_leaf(node->right, word);
	}

	return 0;
}

int count_word_occurrence_left_to_right(CharNode* node, const char* word)
{
	if (node == nullptr)
	{
		return 0;
	}

	int h = height_charnode(node);
	int result = 0;

	for (int i = 0; i < h; i++)
	{
		std::vector<char> res;
		get_level_charnode(node, i, res);

		if (vector_matches_word(res, word))
			result++;
	}

	return result;
}

//Counting occurrence from left to right and from root to leaf
int count_occ(CharNode* node, const char* word)
{
	return count_word_occurrence_left_to_right(node, word) + count_word_occurrence_root_to_leaf(node, word);
}

int main()
{
	Node* root =
		new Node{ 1,
			new Node{2,
				new Node{8, nullptr, nullptr},
				new Node{5, nullptr, nullptr}},
			new Node{5,
				new Node{10, nullptr, nullptr},
				new Node{12, nullptr, nullptr}} };

	Node* errorRoot =
		new Node{ 5, new Node{3, nullptr, nullptr}, nullptr };
	
	
	//Test task 1:
	try
	{
		std::cout << maxpath(root) << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cout << err.what() << std::endl;
	}

	try
	{
		std::cout << maxpath(errorRoot) << std::endl;
	}
	catch(const std::exception& err)
	{
		std::cout << err.what() << std::endl;
	}

	std::cout << std::endl << std::endl;

	//Test task 2:
	std::vector<int> res = average(root);

	for (int i = 0; i < res.size(); i++)
	{
		std::cout << res[i] << " ";
	}

	std::cout << std::endl << std::endl << std::endl;

	//Test task 3:
	CharNode* charRoot =
		new CharNode{ 'c',
			new CharNode{'a',
				new CharNode{'c', nullptr, nullptr},
			nullptr},
				new CharNode{'a',
					new CharNode{'a', nullptr, nullptr},
					new CharNode{'c', nullptr, nullptr}}};

	std::cout << count_occ(charRoot, "cac") << std::endl; //3
	print(charRoot, 5);

	std::cout << std::endl<< std::endl;

	CharNode* test =
		new CharNode{ 'c', new CharNode{'c', nullptr, nullptr}, new CharNode{'a', nullptr, nullptr} };
	std::cout << count_occ(test, "ca") << std::endl; //2
	
	print(test, 5);
	
	return 0;
}