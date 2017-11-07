#pragma once

template<typename Type>
class SequenceQueue {
public:
	SequenceQueue(int size) :front(0), count(0), maxSize(size) {
		elements = new Type[size];
		if (elements == nullptr) {
			cout << "初始化队列对象出错" << endl;
			exit(1);
		}
	}
	~SequenceQueue() {
		delete[] elements;
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
	Type * elements;
};

template<typename Type>
void SequenceQueue<Type>::MakeEmpty() {
	this->count = 0;
	this->front = 0;
	this->rear = 0;
}

template<typename Type>
bool SequenceQueue<Type>::IsEmpty() {
	return count == 0;
}

template<typename Type>
bool SequenceQueue<Type>::IsFull() {
	return count == maxSize;
}

template<typename Type>
bool SequenceQueue<Type>::Append(const Type item) {
	if (IsFull()) {
		cout << "队列超载" << endl;
		return false;
	}
	elements[rear] = item;
	rear = (rear + 1) % maxSize;
	count++;
	return true;
}

template<typename Type>
Type SequenceQueue<Type>::Delete() {
	if (IsEmpty()) {
		cout << "没有可删除的元素" << endl;
		exit(1);
	}
	Type temp = elements[front];
	front = (front + 1) % maxSize;
	count--;
	return temp;
}

template<typename Type>
Type SequenceQueue<Type>::Get() {
	if (IsEmpty()) {
		cout << "没有可删除的元素" << endl;
		exit(1);
	}
	return elements[front];
}

template<typename Type>
void SequenceQueue<Type>::Print() {
	cout << endl << "front";
	for (int i = 0; i < count; i++) {
		cout << "->" << elements[(front + i + maxSize) % maxSize];
	}
	cout << "->rear" << endl;
}