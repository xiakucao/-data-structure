#include "BinTree.h"
#include<iostream>
#include<stack>

BinTree::BinTree()
{
	root = NULL;
}

void BinTree::CreatBinTree(pNode &root)
{
	T temp;
	while (std::cin >> temp) {
		if (temp == '#') {
			root = NULL;
		}
		else {
			root = new struct Node;
			root->key = temp;
			CreatBinTree(root->left);
			CreatBinTree(root->right);
		}
	}
}

pNode BinTree::find(pNode root,T & data) const
{
	if (root == NULL) {
		return NULL;
	}
	if (root->key == data) {
		return root;
	}
	else {
		find(root->left, data);
		find(root->right, data);
	}
}

void BinTree::preorder(pNode &t) const
{
	std::stack<pNode> stack;
	pNode p = t;
	while (!p||stack.empty()) {
		if (p != NULL) {
			stack.push(p);
			std::cout << p->key << " ";
			p = p->left;
		}
		else {
			p = stack.top();
			stack.pop();
			p = p->right;
		}
	}
	std::cout << std::endl;
}

void BinTree::midorder(pNode &t) const
{

}

void BinTree::postorder(pNode &t) const
{

}

void BinTree::levelorder(pNode &t) const
{

}

int BinTree::high(pNode &t) const
{
	return 0;
}

BinTree::~BinTree()
{
}
