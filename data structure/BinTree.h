#pragma once

typedef char T;
typedef struct Node {
	T key;
	struct Node* left;
	struct Node* right;
}*pNode;

class BinTree {
public:
	BinTree();
	void CreatBinTree(pNode &root);
	bool find(pNode root,T data);
	void preorder(pNode root);
	void midorder(pNode root);
	void postorder(pNode root);
	void levelorder(pNode root);
	int high(pNode root);
	~BinTree();
	pNode root;
};
