#include <iostream>

struct Node {
	int val;
	Node* left;
	Node* right;
};

Node* insTree(Node* tree, int data) {
	if (tree == NULL)
	{
		tree = new Node;
		tree->val = data;
		tree->left = NULL;
		tree->right = NULL;
	}
	else
		if (data < tree->val)
			tree->left = insTree(tree->left, data);
		else
			tree->right = insTree(tree->right, data);
	return tree;
}

void printTree(Node* tree)
{
	if (tree)
	{
		std::cout << tree->val;
		if (tree->left || tree->right)
		{
			std::cout << '(';
			if (tree->left)
				printTree(tree->left);
			else
				std::cout << "NULL";
			std::cout << ',';
			if (tree->right)
				printTree(tree->right);
			else
				std::cout << "NULL";
			std::cout << ')';
		}
	}
}

int height(Node* tree)
{
	if (tree == NULL)
		return 0;
	return (height(tree->left) >= height(tree->right)) ? height(tree->left) + 1 : height(tree->right) + 1;
}

bool checkTreeBalance(Node* tree)
{
	if (tree->right != NULL && tree->left != NULL) 
	{ 
		checkTreeBalance(tree->left); 
		checkTreeBalance(tree->right);
		if (abs(height(tree->left) - height(tree->right)) > 1)
			return 0;
		return 1;
	}
}

void delTree(Node* tree) {
	if (tree != NULL) {
		delTree(tree->left);
		delTree(tree->right);
		delete tree;
	}
}

int main()
{
	//task 1
	Node* tree = NULL;
	tree = insTree(tree, 10);
	insTree(tree, 8);
	insTree(tree, 19);
	insTree(tree, 5);
	insTree(tree, 9);
	insTree(tree, 16);
	insTree(tree, 21);
	insTree(tree, 22);
	insTree(tree, 23);
	printTree(tree);
	std::cout << std::endl;
	if (checkTreeBalance(tree))
	{
		std::cout << "Balanced" << std::endl;
	}
	else
	{
		std::cout << "Not balanced" << std::endl;
	}
	delTree(tree);
	//task 2
	srand(10000);
	double count = 0;
	for (size_t i = 0; i < 50; i++)
	{
		Node* tree2 = NULL;
		tree2 = insTree(tree2, rand());
		std::cout << tree2->val << ' ';
		for (size_t j = 1; j < 10000; j++)
		{
			int x = rand();
			insTree(tree2, x);
		}
		if (checkTreeBalance(tree2))
			count++;
		delTree(tree2);
	}
	std::cout << count/1000 << "% balanced" << std::endl;
}