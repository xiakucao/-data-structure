#pragma once

#include<string>

using namespace std;

template<typename Type>
struct ListNode {
	Type val;
	ListNode *next;
	ListNode(Type x):val(x),next(NULL){}
};

template<typename Type>
class LinkedList {
public:
	LinkedList();
	bool insert(Type val, int pos);
	void remove(Type val);
	int size() const;
	int find(const Type &val) const;
	void reserv();
	void print();
	~LinkedList();
private:
	ListNode<Type> *head;
	int length;
};

template<typename Type>
inline LinkedList<Type>::LinkedList() {
	head = NULL;
	length = 0;
}

template<typename Type>
bool LinkedList<Type>::insert(Type val, int pos) {
	if (pos < 0) {
		cout << "The n must be positive" << endl;
		return 0;
	}
	ListNode<Type> *temp = head;
	ListNode<Type> *node = new ListNode<Type>(val);
	if (head == NULL) {
		head = node;
		++length;
		return 1;
	}
	if (pos == 0) {
		node->next= temp;
		head = node;
		++length;
		return 1;
	}
	for (int i = 1; i != pos; ++i) {
		temp = temp->next;
	}
	if (temp == NULL) {
		cout << "insert failed" << endl;
		return 0;
	}
	node->next = temp->next;
	temp->next = node;
	++length;
	return 1;
}

template<typename Type>
void LinkedList<Type>::remove(Type val)
{
	int pos = find(val);
	if (pos == -1)
		return;
	if (pos == 1) {
		head = head->next;
		--length;
		return;
	}
	ListNode<Type> *temp = head;
	for (int i = 2; i < pos; ++i) {
		temp = temp->next;
	}
	temp->next = temp->next->next;
	--length;
}

template<typename Type>
inline int LinkedList<Type>::size() const
{
	cout << length << endl;
	return length;
}

template<typename Type>
int LinkedList<Type>::find(const Type & val) const
{
	if (head == NULL)
		return -1;
	ListNode<Type> *temp = head;
	int count = 1;
	while ((temp->val) != val) {
		++count;
		temp = temp->next;
		if (temp == NULL)
			return -1;
	}
	cout << count << endl;
	return count;
}

template<typename Type>
void LinkedList<Type>::reserv()
{
	if(head==NULL)
            return;
	ListNode<Type> *froTemp = head, *nextTemp = head->next, *temp;
	while (nextTemp != NULL) {
		temp = nextTemp->next;
		nextTemp->next = froTemp;
		froTemp = nextTemp;
		nextTemp = temp;
	}
	head->next = NULL;
	head = froTemp;
}

template<typename Type>
void LinkedList<Type>::print()
{
	ListNode<Type> *temp = head;
	while (temp != NULL) {
		cout << temp->val << " ";//内置类型
		temp = temp->next;
	}
	cout << endl;
}

template<typename Type>
inline LinkedList<Type>::~LinkedList()
{
	ListNode<Type> *del = head;
	while (head->next!= NULL) {
		del = head->next;
		head->next = del->next;
		delete del;
	}
	delete head;
	cout << "调用了析构函数" << endl;
}
