#pragma once

typedef char T;
typedef struct Node {
	T data;
	Node *left;
	Node *right;
}*pNode;

class BinSearchTree {
public:
	BinSearchTree();
	void CreatBinSearchTree(pNode root);
	bool find(pNode root,T &data)const;
	T findMax(pNode root)const;
	T findMin(pNode root)const;
	void insert(pNode root, T &data);
	void del(pNode root, T &data);
private:
	pNode root;
};
