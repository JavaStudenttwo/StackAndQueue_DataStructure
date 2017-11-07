#pragma once

template<typename Type>
class SequenceStack {
public:
	SequenceStack(int size) :top(-1),maxSize(size) {
		elements = new Type[size];
		if (elements == nullptr) {
			cout << "初始化栈对象出错" << endl;
			exit(1);
		}
	}
	~SequenceStack() {
		delete[] elements;
	}
	//返回栈的信息的方法
	bool IsEmpty();
	bool IsFull();
	//对栈内元素的操作
	void MakeEmpty();
	void Push(const Type item);
	Type Pop();
	Type GetTop() const;
	//基本方法
	void Print();

private:
	int top;
	int maxSize;
	Type * elements;
};

template<typename Type>
void SequenceStack<Type>::MakeEmpty() {
	this->top == -1;
}

template<typename Type>
bool SequenceStack<Type>::IsEmpty() {
	return top == -1;
}

template<typename Type>
bool SequenceStack<Type>::IsFull() {
	return top == maxSize-1;
}

template<typename Type>
void SequenceStack<Type>::Push(const Type item) {
	if (IsFull()) {
		cout << "栈溢出" << endl;
		exit(1);
	}
	elements[++top] = item;
}

template<typename Type>
Type SequenceStack<Type>::Pop() {
	if (IsEmpty()) {
		cout << "没有可删除的元素" << endl;
		exit(1);
	}
	return elements[top--];
}

template<typename Type>
Type SequenceStack<Type>::GetTop() const{
	if (IsEmpty()) {
		cout << "没有可删除的元素" << endl;
		exit(1);
	}
	return elements[top];
}

template<typename Type>
void SequenceStack<Type>::Print() {
	cout << endl << "bottom";
	for (int i = 0; i <= top; i++) {
		cout << "->" << elements[i];
	}
	cout << "->top" << endl;
}