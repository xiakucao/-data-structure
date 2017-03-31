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
	pNode find(pNode root,T &data) const;
	void preorder(pNode &t) const;
	void midorder(pNode &t) const;
	void postorder(pNode &t) const;
	void levelorder(pNode &t) const;
	int high(pNode &t) const;
	~BinTree();
private:
	pNode root;
};
