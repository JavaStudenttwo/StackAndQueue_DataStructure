#pragma once

template<typename Type>
class SequenceStack {
public:
	SequenceStack(int size) :top(-1),maxSize(size) {
		elements = new Type[size];
		if (elements == nullptr) {
			cout << "��ʼ��ջ�������" << endl;
			exit(1);
		}
	}
	~SequenceStack() {
		delete[] elements;
	}
	//����ջ����Ϣ�ķ���
	bool IsEmpty();
	bool IsFull();
	//��ջ��Ԫ�صĲ���
	void MakeEmpty();
	void Push(const Type item);
	Type Pop();
	Type GetTop() const;
	//��������
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
		cout << "ջ���" << endl;
		exit(1);
	}
	elements[++top] = item;
}

template<typename Type>
Type SequenceStack<Type>::Pop() {
	if (IsEmpty()) {
		cout << "û�п�ɾ����Ԫ��" << endl;
		exit(1);
	}
	return elements[top--];
}

template<typename Type>
Type SequenceStack<Type>::GetTop() const{
	if (IsEmpty()) {
		cout << "û�п�ɾ����Ԫ��" << endl;
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