#include "BinTree.h"
#include<iostream>
#include<stack>
#include<queue>

BinTree::BinTree()
{
	root = NULL;
}

void BinTree::CreatBinTree(pNode root)
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
			CreatBinTree(root->right);//层序创建树；
		}
	}
}

pNode BinTree::find(pNode root,T data) const
{
	if (root == NULL) {
		return NULL;
	}
	if (root->key == data) {
		return root;
	}
	else {
		find(root->left, data);
		find(root->right, data);//层序遍历查找
	}
}

//前序遍历
void BinTree::preorder(pNode root) const
{
	std::stack<pNode> stack;
	//防止无意中修改root
	pNode p = root;
	while (p||!stack.empty()) {
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

//中序遍历
void BinTree::midorder(pNode root) const
{
	std::stack<pNode> stack;
	pNode p = root;
	while (p || !stack.empty()) {
		if (p != NULL) {
			stack.push(p);
			p = p->left;
		}
		else {
			p = stack.top();
			std::cout << p->key << " ";
			stack.pop();
			p = p->right;
		}
	}
	std::cout << std::endl;
}

//后序遍历
void BinTree::postorder(pNode root) const
{
	//后序遍历要先遍历左右子树再访问根
	std::stack<pNode> stack;
	pNode p = root;
	while (true) {
		while (p != NULL) {
			stack.push(p);
			p = p->left;
		}
		while (!stack.empty() && stack.top()->right == p) {
			std::cout << stack.top()->key << std::endl;
			stack.pop();
		}
		if (stack.empty()) {
			break;
		}
		p = stack.top()->right;
	}
}

//层序遍历
void BinTree::levelorder(pNode root) const
{
	std::queue<pNode> queue;
	pNode p = root;
	//层序遍历后面每次最多压入两个元素，这个根节点需要在while外部压入了
	if (p != NULL) {
		queue.push(p);
	}
	while (!queue.empty()) {
		p = queue.front();
		if (p->left != NULL) {
			queue.push(p->left);
		}
		if (p->right != NULL) {
			queue.push(p->right);
		}
		queue.pop();
		std::cout << p->key << " ";
	}
	std::cout << std::endl;
}

//求树的深度
int BinTree::high(pNode root) const
{
	//pNode p = root;没必要了，后面不需要更改root值
	int h = 0, left = 0, right = 0;
	if (root == NULL) {
		return 0;
	}
	left = high(root->left);
	right = high(root->right);
	h = (left > right ? left : right) + 1;
	return 0;
}

//析构函数
BinTree::~BinTree()
{
	std::queue<pNode> queue;
	pNode p = root;
	if (p != NULL) {
		queue.push(p);
	}
	while (!queue.empty()) {
		p = queue.front();
		if (p->left != NULL) {
			queue.push(p->left);
		}
		if (p->right != NULL) {
			queue.push(p->right);
		}
		queue.pop();
		delete p;
	}
}
