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
class PriorityQueue;

template <class T, int N>
class Node {
public:
	T value;
	int priority;
	Node<T, N>* next;

	Node(T value, int priority) : value(value), priority(priority), next(nullptr) {}

	friend class PriorityQueue<T, N>;
};


template <class T, int N>
class PriorityQueue {
private:
	Node<T, N>* front{ nullptr };

public:
	PriorityQueue();
	~PriorityQueue();
	void clear();
	bool IsEmpty() const;
	bool IsFull() const;
	int size() const;
	void InsertWithPriority(const T& value, int priority);
	T PullHighestPriorityElement();
	T Peek() const;
	void Show() const;
};

template <class T, int N>
PriorityQueue<T, N>::PriorityQueue() {} 

template <class T, int N>
PriorityQueue<T, N>::~PriorityQueue() {
	clear();
}

template <class T, int N>
void PriorityQueue<T, N>::clear() {
	Node<T, N>* temp;
	while (front != nullptr) {
		temp = front;
		front = front->next;
		delete temp;
	}
	front = nullptr;
}

template <class T, int N>
void PriorityQueue<T, N>::InsertWithPriority(const T& value, int priority) {
	Node<T, N>* temp = new Node<T, N>(value, priority);

	if (front == nullptr) {
		front = temp;
		return;
	}
	if (priority > front->priority) {
		temp->next = front;
		front = temp;
		return;
	}
	Node<T, N>* current = front->next;
	Node<T, N>* previous = front;
	while (current != nullptr && current->priority >= priority) {
		previous = current;
		current = current->next;
	}
	temp->next = current;
	previous->next = temp;
}

template <class T, int N>
T PriorityQueue<T, N>::PullHighestPriorityElement() {
	assert(front != nullptr && "Queue is empty");
	T value = front->value;      // копия, не ссылка
	Node<T, N>* temp = front;
	front = front->next;
	delete temp;
	return value;
}

template <class T, int N>
T PriorityQueue<T, N>::Peek() const {
	assert(front != nullptr && "Queue is empty");
	return front->value;
}


template <class T, int N>
void PriorityQueue<T, N>::Show() const {
	if (front == nullptr) {
		cout << "Queue is empty" << endl;
		return;
	}
	Node<T, N>* current = front;
	while (current != nullptr) {
		cout << "Value: " << current->value << ", Priority: " << current->priority << endl;
		current = current->next;
	}
}

template <class T, int N>
bool PriorityQueue<T, N>::IsEmpty() const {
	return (front == nullptr) ? true : false;
}

template <class T, int N>
bool PriorityQueue<T, N>::IsFull() const {
	return (size() == N) ? true : false;
}

template <class T, int N>
int PriorityQueue<T, N>::size() const {
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
	PriorityQueue<string, 5> pq;

	cout << "Empty? " << pq.IsEmpty() << endl;   // 1 (true)

	cout << "\n--- Insert elements with different priorities ---\n";
	pq.InsertWithPriority("Task A", 3);
	pq.InsertWithPriority("Task B", 5);
	pq.InsertWithPriority("Task C", 1);
	pq.InsertWithPriority("Task D", 4);
	pq.InsertWithPriority("Task E", 2);

	cout << "Full? " << pq.IsFull() << endl;      // 1, N=5
	cout << "Size: " << pq.size() << endl;

	cout << "\n--- Show (must be sorted by priority, high to low) ---\n";
	pq.Show();

	cout << "\n--- Peek (must not remove) ---\n";
	cout << "Peek: " << pq.Peek() << endl;
	cout << "Size after peek: " << pq.size() << endl;   // размер не изменился

	cout << "\n--- Pull all elements one by one ---\n";
	while (!pq.IsEmpty()) {
		cout << "Pulled: " << pq.PullHighestPriorityElement() << endl;
	}

	cout << "\nEmpty after pulling all? " << pq.IsEmpty() << endl;  // 1

	system("pause");
}