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
	Array& operator=(const Array& other);
	~Array() {
		if (arr != nullptr) {
			delete[] arr;
			arr = nullptr;
			cout << "Destructor called" << endl;
		}
	}


	int operator[](int idx) const;
	int& operator[](int idx);
	Array& operator()(int value);
	friend std::ostream& operator<<(std::ostream& out, const Array& obj);
	friend std::istream& operator>>(std::istream& in, Array& obj);
	bool operator>(const Array& other) const;
	bool operator<(const Array& other) const;
	operator int() const;
	operator char* () const;

	void resize(int newSize);
};


void Array::resize(int newSize) {
	delete[] arr;

	size = newSize;
	arr = new int[size];
}

void Array::input() {
	cout << "Input how many elements will be in array: ";
	cin >> size;

	delete[] arr;
	arr = new int[size];

	for (int i = 0; i < size; ++i) {
		cout << "Enter number: ";
		cin >> arr[i];
	}
}

void Array::show() {
	for (int i = 0; i < size; ++i) {
		cout << arr[i];
	}
}

void Array::setNew_number(int index) {
	assert(index >= 0 && index < size && "Index is out of range!");

	cout << "Enter new number: ";
	cin >> arr[index];
}

Array::Array(const Array& other) {
	size = other.size;
	arr = new int[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = other.arr[i];
	}
}

Array& Array::operator=(const Array& other) {
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

int Array::operator[](int idx) const {
	assert(idx >= 0 && idx < size && "Index is out of range!");
	return arr[idx];
}

int& Array::operator[](int idx) {
	assert(idx >= 0 && idx < size && "Index is out of range!");
	return arr[idx];
}

Array& Array::operator()(int value) {
	for (int i = 0; i < size; ++i) {
		arr[i] += value;
	}
	return *this;
}

ostream& operator<<(ostream& out, const Array& obj) {
	for (int i = 0; i < obj.size; ++i) {
		out << obj.arr[i] << ' ';
	}
	return out;
}
istream& operator>>(istream& in, Array& obj) {
	for (int i = 0; i < obj.size; ++i) {
		in >> obj.arr[i];
	}
	return in;
}

bool Array::operator>(const Array& other) const {
	int sum_this = 0;
	for (int i = 0; i < size; ++i) {
		sum_this += arr[i];
	}

	int sum_other = 0;
	for (int i = 0; i < other.size; ++i) {
		sum_other += other.arr[i];
	}

	return sum_this > sum_other;
}

bool Array::operator<(const Array& other) const {
	int count_this = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] > 31) {
			count_this++;
		}
	}
	int counter_other = 0;
	for (int i = 0; i < other.size; ++i) {
		if (other.arr[i] > 31) {
			counter_other++;
		}
	}

	return count_this < counter_other;

}

Array::operator int() const {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}

Array::operator char* () const {
	static char buffer[256] = {};
	buffer[0] = '\0';

	char temp[16];
	for (int i = 0; i < size; ++i) {
		sprintf_s(temp, "%d ", arr[i]);
		strcat_s(buffer, temp);
	}
	return buffer;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

	cout << "--- Test input/output ---" << endl;
	Array a1;
	a1.input();
	a1.show();

	cout << "\n--- Test operator<< ---" << endl;
	cout << a1 << endl;

	cout << "\n--- Test copy constructor ---" << endl;
	Array a2(a1);
	a2.show();

	cout << "\n--- Test operator= ---" << endl;
	Array a3;
	a3 = a1;
	a3.show();

	cout << "\n--- Test operator[] ---" << endl;
	cout << "a1[0] = " << a1[0] << endl;
	a1[0] = 100;
	cout << "a1[0] after change = " << a1[0] << endl;

	cout << "\n--- Test operator() ---" << endl;
	a1(5);
	a1.show();

	cout << "\n--- Test operator>> ---" << endl;
	Array a4;

	cout << "Enter size for a4: ";
	int n;
	cin >> n;

	a4.resize(n);

	cout << "Enter " << n << " numbers:\n";
	cin >> a4;

	a4.show();

	cout << "\n--- Test operator> and operator< ---" << endl;
	cout << "a1 > a3: " << (a1 > a3) << endl;
	cout << "a1 < a3: " << (a1 < a3) << endl;

	int sum = a1;           // сработает operator int()
	char* s = a1;            // сработает operator char*()
	cout << s << endl;

	return 0;

}


