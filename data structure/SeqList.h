/*
 * Sequence List.
 * 
 * Created on:2017.3.10.
 *     Author:Fc
 */
#pragma once

#include<iostream>
#include<vector>

const size_t ListInitSize = 50;// initial size.

template<typename Type>
class SeqList {
public:
	SeqList(size_t sz = ListInitSize);
	int length()const;
	std::vector<int> find(const Type &key)const;
	void delete_pos(size_t pos);
	void delete_val(const Type &key);
	void push_back(const Type &key);
	void push_front(const Type &key);
	void pop_back();
	void pop_front();
	void insert(size_t pos, const Type &key);
	void clear();
	void reserv();
	void sort();
	void swap(size_t pos1, size_t pos2);
	void show();
	~SeqList() {
		delete[] element;
		std::cout << "调用了析构函数" << std::endl;
	}
private:
	Type *element;
	size_t capacity;
	size_t size;
};

template<typename Type>
SeqList<Type>::SeqList(size_t sz){
	capacity = ListInitSize;
	element = new Type(capacity);
	sz = 0;
}

//返回list大小
template<typename Type>
inline int SeqList<Type>::length()const {
	return size;
}

//找到指定大小的所有元素，并返回所在位置，从1计数
template<typename Type>
std::vector<int> SeqList<Type>::find(const Type & key) const
{
	int pos = 1;
	vector<int> obj;
	for (int i = 0; i != size;++i) {
		if (element[i] != key) {
			++pos;
		}
		else {
			obj.push_back(pos);
			++pos;
		}
	}
	for (auto i : obj) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return obj;
}

//删除指定位置的元素，从1开始计数
template<typename Type>
void SeqList<Type>::delete_pos(size_t pos)
{
	if (pos > size || pos < 1) {
		std::cout << pos << std::endl;
		std::cerr << "位置不在范围内" << std::endl;
	}
	else {
		if (pos == size) {
			pop_back();
		}
		else {
			for (int i = pos - 1; i != size - 1; ++i) {
				element[i] = element[i + 1];
			}
			--size;
		}
	}
}

//删除指定大小的所有元素
template<typename Type>
void SeqList<Type>::delete_val(const Type & key)
{
	int i = 0, temp = 0;
	vector<int> obj = find(key);
	while (i != obj.size()) {
		delete_pos(obj[i]-temp);
		++i;
		++temp;
	}
}

//在尾后添加元素
template<typename Type>
inline void SeqList<Type>::push_back(const Type & key)
{
	if (size < capacity) {
		element[size++] = key;
	}
	else {
		std::cerr << "空间已满，不能添加" << std::endl;
	}
}

//在头添加元素
template<typename Type>
void SeqList<Type>::push_front(const Type & key)
{
	if (size < capacity) {
		for (int i = size; i != 0; --i) {
			element[i] = element[i - 1];
		}
		element[0] = key;
		++size;
	}
	else {
		std::cerr << "空间已满，不能添加" << std::endl;
	}
}

//弹出尾元素
template<typename Type>
inline void SeqList<Type>::pop_back()
{
	if (size != 0)
		--size;
}

//弹出头元素
template<typename Type>
void SeqList<Type>::pop_front()
{
	if (size != 0) {
		for (int i = 0; i != size; ++i) {
			element[i] = element[i + 1];
		}
		--size;
	}
}

//在指定位置添加元素
template<typename Type>
void SeqList<Type>::insert(size_t pos, const Type & key)
{
	if (size < capacity) {
		for (int i = size; i != pos-1; --i) {
			element[i] = element[i - 1];
		}
		element[pos - 1] = key;
		++size;
	}
	else {
		std::cout << "容量已满或添加位置不在范围内" << std::endl;
	}
}

template<typename Type>
inline void SeqList<Type>::clear()
{
	while (size) {
		element[--size] = NULL;
	}
}

template<typename Type>
void SeqList<Type>::reserv()
{
	int temp = 0;
	if (size>1) {
		for (int i = 0, j = size - 1; i < j; ++i, --j) {
			swap(i, j);
		}
	}
}

template<typename Type>
void SeqList<Type>::sort()
{
	if (size > 1) {
		for (int i = 1; i != size; ++i) {
			for (int j = i; j != 0; --j) {
				if (element[j] < element[j - 1])
					swap(j, j - 1);
			}
		}
	}
	return;
}

template<typename Type>
inline void SeqList<Type>::swap(size_t pos1, size_t pos2)
{
	int temp = 0;
	temp = element[pos1];
	element[pos1] = element[pos2];
	element[pos2] = temp;
}

template<typename Type>
inline void SeqList<Type>::show()
{
	for (int i = 0; i != size;++i) {
		std::cout << element[i] << " ";
	}
	std::cout << std::endl;
}
