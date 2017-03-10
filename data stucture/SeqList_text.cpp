#include<iostream>
#include<vector>
#include"SeqList.h"

using namespace std;

int main()
{
	SeqList<int> text;
	int array[10] = { 7,3,1,4,8,2,9,10,5,6};
	for (int i = 1; i != 11; ++i) {
		text.insert(i, array[i-1]);
	}
	text.push_back(11);
	text.push_front(11);
	text.find(11);
	text.delete_pos(5);
	text.delete_val(11);
	text.pop_back();
	text.pop_front();
	text.sort();
	text.reserv();
	text.show();
	return 0;
}
