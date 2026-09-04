#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <windows.h>
#include <cassert>
#include <conio.h>
#include <stack>
using namespace std;







template <class T>

class Stack {
private:
	T value;
	Node<T>* next;
	friend ostream& operator<<(ostream& s, const Stack<T>& next) {
		s << value << endl;
		return s;
	}
public:

	Stack(T value) : value(value), next(nullptr) {}

	friend class Mystack<T>;
};


template <class T>
class MyStack {
private:

	Node<T> top{ nullptr };


public:
	MyStack();
	void push(const T& value); // push item to stack top
	void pop();                // remove item from stack top
	T& retTop() const;            // return stack top item
	bool empty() const;        // if stack is empty
	int size() const;          // stack size
	~MyStack();
	friend ostream& operator<<(ostream& s, const Stack<T>& stck) {
		return s;
	}
};
template <class T>
MyStack<T>::~MyStack<T>() {

	Node<T>* temp;
	while (top != nullptr) {
		temp = top;
		top = top->next;
		delete temp;
	}
	top = nullptr;

}





template <class T>
void MyStack<T>::push(const T& value) {
	Node<T>* temp = new Node<T>{value};
	temp->next = top;
	top = temp;
}

template <class T>
void MyStack<T>::pop() {
	if (!empty()) {
		Node<T>* temp = top;
		top = top->next;
		delete temp;

	}
	else {
		cout << "Stack is empty" << endl;
	}
}


template <class T>
T& MyStack<T>::retTop() const {
	assert(top != nullptr && "Stack is empty");
	return top->value;
}

template <class T>
bool MyStack<T>::empty() const {
	return(top == nullptr) ? true : false;
}

template <class T>
int MyStack<T>::size() const {
	int count = 0;
	Node<T>* current = top;
	while (current != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}

int main()
{ 




}


