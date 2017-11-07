#pragma once
#include"LinkedQueueNode.h"

template<typename Type>
class LinkedQueue {
public:
	LinkedQueue(int size) :front(0), count(0), maxSize(size), head(new LinkedQueueNode<Type>()) {
		LinkedQueueNode<Type> * pmove = head;
		for (int i = 0; i < size; i++){
			LinkedQueueNode<Type> * pnode = new LinkedQueueNode<Type>;
			pmove->pnext = pnode;
			pmove = pmove->pnext;
		}
		pmove->pnext = head->pnext;
	}
	~LinkedQueue() {
		MakeEmpty();
		delete head;
	}
	//返回队列的信息的方法
	bool IsEmpty();
	bool IsFull();
	//对队列内元素的操作
	void MakeEmpty();
	bool Append(const Type item);
	Type Delete();
	Type Get();
	//基本方法
	void Print();

private:
	int rear;
	int front;
	int count;
	int maxSize;
	LinkedQueueNode<Type> * head;
};

template<typename Type>
void LinkedQueue<Type>::MakeEmpty() {
	LinkedQueueNode<Type> *pdel;
	while (head->pnext != nullptr)
	{
		pdel = head->pnext;
		head->pnext = pdel->pnext;
		delete pdel;
	}
}

template<typename Type>
bool LinkedQueue<Type>::IsEmpty() {
}

template<typename Type>
bool LinkedQueue<Type>::IsFull() {
}

template<typename Type>
bool LinkedQueue<Type>::Append(const Type item) {
	LinkedQueueNode<Type> * pmove = head;
	for (int i = 0; i < rear; i++){
		pmove = pmove->pnext;
	}
	pmove->data = item;
	rear++;
	count++;
	return true;
}

template<typename Type>
Type LinkedQueue<Type>::Delete() {
	LinkedQueueNode<Type> * pmove = head;
	for (int i = 0; i < rear; i++) {
		pmove = pmove->pnext;
	}
	Type temp = pmove->data;
	front++;
	count++;
	return temp;
}

template<typename Type>
Type LinkedQueue<Type>::Get() {
	Type temp = 0;
	return temp;
}

template<typename Type>
void LinkedQueue<Type>::Print() {
}