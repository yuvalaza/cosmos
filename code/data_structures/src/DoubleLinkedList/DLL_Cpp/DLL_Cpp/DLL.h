#pragma once
#include "Node.h"
template <typename T>
class DLL
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	DLL();
	bool isEmpty()const;
	int Getsize()const;
	void addFirst(T data);
	void addlast(T data);
	void add(T data, int index=0);
	void deleteNode(int index=0);
};

