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
	pNode CreatBinTree(pNode root);
	pNode find(pNode root,T data) const;
	void preorder(pNode root) const;
	void midorder(pNode root) const;
	void postorder(pNode root) const;
	void levelorder(pNode root) const;
	int high(pNode root) const;
	~BinTree();
private:
	pNode root;
};
