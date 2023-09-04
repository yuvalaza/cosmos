#include "DLL.h"


template <typename T>
DLL<T>::DLL() {
	this->head = nullptr;
	this->tail - nullptr;
	this->size = 0;
}

template <typename T>
bool DLL<T>::isEmpty() const {
	return this->size == 0;
}

template <typename T>
int DLL<T>::Getsize()const {
	return this->size;
}

template <typename T>
void DLL<T>::addFirst(T data){
	Node<T>* newNode = new Node<T>(data);
	this->size++;

	if (isEmpty()) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
		newNode->next = this->head;
		this->head->prev = newNode;
		this->head = newNode;
	}
	this->size++;
}

template <typename T>
void DLL<T>::addlast(T data) {
	Node<T>* newNode = new Node<T>(data);

	if (isEmpty()) {
		this->head = newNode;
		this->tail = newNode;
	}
	else {
			newNode->prev = this->tail;
			this->tail->next = newNode;
			this->tail = newNode;
	}
	this->size++;
}
template <typename T>
void DLL<T>::add(T data, int index) {
	if (index < 0 || index >= size) {
		throw ErrorObject(INVALID_INDEX_NUM, INVALID_INDEX);
	}
	if (index == 0) {
		this->addFirst(data);
		return;
	}
	if (index == this->size-1) {
		this->addlast(data);
		return;
	}
	Node<T>* newNode = new Node<T>(data);
	Node<T>* temp = this->head;
	for (int i = 1; i < index - 1; i++) {
		temp = temp->next;
	}
	newNode->prev = temp;
	newNode->next = temp->next;
	if (temp->next) {
		temp->next->prev = newNode;
	}
	temp->next = newNode;
	this->size++;
}

template <typename T>
void DLL<T>::deleteNode(int index) {
	if (index < 0 || index >= size) {
		throw ErrorObject(INVALID_INDEX_NUM, INVALID_INDEX);
	}
	Node<T>* temp = head;
	if (index == 0) {
		head = head->next;
		if (head) {
			head->prev = nullptr;
		}
		delete temp;
		size--;
		return;
	}

	if (index == this->size - 1) {
		Node<T>* toDelete = tail;
		tail = tail->prev;
		delete toDelete;
		size--;
		return;
	}

	for (int i = 0; i < index; i++) {
		temp = temp->next;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	delete temp;
	size--;
}

template <typename T>
void DLL<T>::display()const {
	if (isEmpty()) {
		cout << "None" << endl;
	}
	else
	{
		Node<T>* temp = head;
		cout << temp->data+" " << endl;
		while (temp->next) {
			temp = temp->next;
			cout << temp->data + " " << endl;
		}

	}

	
}