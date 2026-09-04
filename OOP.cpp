#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <windows.h>
#include <cassert>
#include <conio.h>
#include <stack>
using namespace std;

template <class T, int N>
class MyStack;

template <class T, int N>
class Node {
public:
	T value;
	Node<T, N>* next;

	Node(T value) : value(value), next(nullptr) {}

	friend ostream& operator<<(ostream& s, const Node<T, N>& n) {
		s << n.value << endl;
		return s;
	}

	friend class MyStack<T, N>;
};


template <class T, int N>
class MyStack {
private:
	Node<T, N>* top{ nullptr }; 

public:
	MyStack();
	void push(const T& value);
	void pop();
	T& retTop() const;
	bool empty() const;
	int size() const;
	bool isFull()const;
	~MyStack();
	void clear();
};

template <class T, int N>
MyStack<T, N>::MyStack() {} 

template <class T, int N>
MyStack<T, N>::~MyStack() {
	clear();
}

template <class T, int N>
void MyStack<T, N>::clear() {
	Node<T, N>* temp;
	while (top != nullptr) {
		temp = top;
		top = top->next;
		delete temp;
	}
	top = nullptr;
}

template <class T, int N>
void MyStack<T, N>::push(const T& value) {
	assert(!isFull() && "Stack is full");
	Node<T, N>* temp = new Node<T, N>(value);
	temp->next = top;
	top = temp;
}

template <class T, int N>
void MyStack<T, N>::pop() {
	if (!empty()) {
		Node<T, N>* temp = top;
		top = top->next;
		delete temp;
	}
	else {
		cout << "Stack is empty" << endl;
	}
}

template <class T, int N>
T& MyStack<T, N>::retTop() const {
	assert(top != nullptr && "Stack is empty");
	return top->value;
}

template <class T, int N>
bool MyStack<T, N>::empty() const {
	return (top == nullptr) ? true : false;
}

template <class T, int N>
bool MyStack<T, N>::isFull() const {
	return (size() == N) ? true : false;
}

template <class T, int N>
int MyStack<T, N>::size() const {
	int count = 0;
	Node<T, N>* current = top;
	while (current != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}

int main()
{
	char str[100]{ "lorem hi to u" };
	cout << "String: " << str << endl;
	MyStack<char, 100> myCharstack;
	for (auto ch : str) {
		myCharstack.push(ch);
	}

	cout << "Stack pop: ";
	while (!myCharstack.empty()) {
		cout << myCharstack.retTop() << " ";
		myCharstack.pop();
	}
	system("pause");
}