#pragma once

template<typename Type> class LinkedQueue;

template<typename Type>
class LinkedQueueNode
{
private:
	friend typename LinkedQueue<Type>;
	//���캯������������
	LinkedQueueNode() :pnext(nullptr) {}
	LinkedQueueNode(const Type item, LinkedQueueNode<Type> * next = nullptr) :data(item), pnext(next) {}
	~LinkedQueueNode() {
		pnext = nullptr;
	}
public:
	Type GetData();
private:
	Type data;
	LinkedQueueNode * pnext;
};

//��ȡ����ڵ��е�����
template<typename Type> Type LinkedQueueNode<Type>::GetData() {
	return this->data;
}
