#include<iostream>
#include"singleList.h"

using namespace std;

int main()
{
	LinkedList<int> list;
	for (int i = 0; i != 10; ++i) {
		list.insert(i,i);
	}
	list.print();
	list.find(1);
	list.remove(2);
	list.print();
	list.insert(10, 0);
	list.print();
	list.reserv();
	list.print();
	list.size();
}
