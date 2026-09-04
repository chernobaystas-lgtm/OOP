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
class MyQueue;

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

	friend class MyQueue<T, N>;
};


template <class T, int N>
class MyQueue {
private:
	Node<T, N>* front{ nullptr };
	Node<T, N>* rear{ nullptr };

public:
	MyQueue();
	void push(const T& value);
	void pop();
	T& retTop() const;
	bool empty() const;
	int size() const;
	bool isFull()const;
	~MyQueue();
	void clear();
};

template <class T, int N>
MyQueue<T, N>::MyQueue() {} 

template <class T, int N>
MyQueue<T, N>::~MyQueue() {
	clear();
}

template <class T, int N>
void MyQueue<T, N>::clear() {
	Node<T, N>* temp;
	while (front != nullptr) {
		temp = front;
		front = front->next;
		delete temp;
	}
	front = nullptr;
	rear = nullptr;
}

template <class T, int N>
void MyQueue<T, N>::push(const T& value) {
	Node<T, N>* temp = new Node<T, N>(value);
	if (rear == nullptr) {
		front = temp;
	}
	else {
		rear->next = temp;
	}
	rear = temp;
}

template <class T, int N>
void MyQueue<T, N>::pop() {
	if (front != nullptr) {
		Node<T, N>* temp = front;
		front = front->next;
		delete temp;
		if (front == nullptr) {
			rear = nullptr;
		}
	}
}			

template <class T, int N>
T& MyQueue<T, N>::retTop() const {
	assert(front != nullptr && "Queue is empty");
	return front->value;
}

template <class T, int N>
bool MyQueue<T, N>::empty() const {
	return (front == nullptr) ? true : false;
}

template <class T, int N>
bool MyQueue<T, N>::isFull() const {
	return (size() == N) ? true : false;
}

template <class T, int N>
int MyQueue<T, N>::size() const {
	int count = 0;
	Node<T, N>* current = front;
	while (current != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}

int main()
{
	MyQueue<int, 5> q;

	cout << "Empty? " << q.empty() << endl;      // 1 (true) - пустая
	cout << "Full? " << q.isFull() << endl;       // 0 (false)
	cout << "Size: " << q.size() << endl;         // 0

	cout << "\n--- Push 5 elements ---\n";
	for (int i = 1; i <= 5; i++) {
		q.push(i * 10);
		cout << "Pushed " << i * 10 << ", size: " << q.size() << endl;
	}

	cout << "\nEmpty? " << q.empty() << endl;     // 0
	cout << "Full? " << q.isFull() << endl;        // 1 - заполнили N=5

	cout << "\n--- Try push into full queue ---\n";
	q.push(999);   // тут посмотришь, что реально произойдёт - улетит без проверки или нет

	cout << "\n--- Pop all elements ---\n";
	while (!q.empty()) {
		cout << "Front: " << q.retTop() << ", size before pop: " << q.size() << endl;
		q.pop();
	}

	cout << "\nEmpty after popping all? " << q.empty() << endl;  // 1
	cout << "Size: " << q.size() << endl;                        // 0

	system("pause");
}