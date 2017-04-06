#include "BinSearchTree.h"
#include<iostream>

BinSearchTree::BinSearchTree()
{
	root = NULL;
}

void BinSearchTree::CreatBinSearchTree(pNode root)
{
	/*T temp;
	std::cin >> temp;
	if (temp == '#') {
		root = NULL;
	}
	else {
		root->data = temp;
		CreatBinSearchTree(root->left);
		CreatBinSearchTree(root->right);
	}*/
}

bool BinSearchTree::find(pNode root,T &data)const
{
	pNode p = root;
	while (p != NULL) {
		if (p->data == data) {
			return true;
		}
		if (p->data > data) {
			p = p->left;
		}
		if (p->data < data) {
			p = p->right;
		}
	}
	return false;
}

T BinSearchTree::findMax(pNode root)const
{
	pNode p = root;
	if (!p) {
		std::cout << "树为空" << std::endl;
		return 0;
	}
	while (p->right != NULL) {
		p = p->right;
	}
	return p->data;
}

T BinSearchTree::findMin(pNode root)const
{
	pNode p = root;
	if (!p) {
		std::cout << "树为空" << std::endl;
		return 0;
	}
	while (p->left != NULL) {
		p = p->left;
	}
	return p->data;
}

void BinSearchTree::insert(pNode root, T & data)
{
	pNode p = root;
	while (p != NULL) {
		if (p->data == data) {
			return;
		}
		if (p->data > data) {
			p = p->left;
		}
		if (p->data < data) {
			p = p->right;
		}
	}
	p->data = data;
}

void BinSearchTree::del(pNode root, T & data)
{

}
