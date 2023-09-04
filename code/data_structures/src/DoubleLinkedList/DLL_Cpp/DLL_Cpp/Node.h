#pragma once
#include "ErrorObj.h"
template <typename T=double>
class Node
{
private:
	T data;
	Node<T>* prev;
	Node<T>* next;
public:
	Node(T val=T()) {
		this->data = val;
		this->prev = nullptr;
		this->next = nullptr;
	}
};

