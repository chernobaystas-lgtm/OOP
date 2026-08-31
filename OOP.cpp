#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <windows.h>
using namespace std;

#define T 20

class Array {
private:
    int* arr{nullptr};
    int size{ 0 };


public:
	void input();
	void show();
	void setNew_number(int index);


	Array() : arr(nullptr), size(0) {
		cout << "Constructor called" << endl;
	}
	Array(int*, int) {
		cout << "Constructor with parameters called" << endl;
	}
	Array(const Array&);
	Array operator=(const Array&);
	~Array() {
		if (arr != nullptr) {
			delete[] arr;
			arr = nullptr;
			cout << "Destructor called" << endl;
		}
	}

};




void Array::input() {
	cout << "input how many elements will br in array";
	cin >> size;
	for (int i = 0; i < size; ++i) {
		cout << "enter number";
		cin >> arr[i];
	}
}

void Array::show() {
	for (int i = 0; i < size; ++i) {
		cout << arr[i];
	}
}

void Array::setNew_number(int index) {
	int new_index = -index;
	cout << "Enter new number ";
	int new_number{ 0 };
	cin >> new_number;
	this->arr[new_index] = new_number;
}
Array::Array(const Array& other) {
	size = other.size;
	arr = new int[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = other.arr[i];
	}
}

Array Array::operator=(const Array& other) {
	if (this == &other) {
		return *this;
	}
	delete[] arr;
	size = other.size;
	arr = new int[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = other.arr[i];
	}
	return *this;
}



int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


}


