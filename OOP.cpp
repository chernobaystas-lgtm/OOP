#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <windows.h>
#include <cassert>
using namespace std;

#define T 20

struct Date {
	int day;
	int month;
	int year;
	void show()const {
		cout << "Date: " << day << "." << month << "." << year << endl;
	}	
	void input() {
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
	}
};


class firstclass_MyPoint {

public: 
	firstclass_MyPoint() : name(nullptr), x(0), y(0), myDate{ 0,0,0 } {
		cout << "Constructor called" << this << endl;
	}
	firstclass_MyPoint(const char*, int, int);
	firstclass_MyPoint(const firstclass_MyPoint&);
	firstclass_MyPoint operator=(const firstclass_MyPoint&);
	firstclass_MyPoint(const char*, int, int, Date&);

	firstclass_MyPoint(const char*);
	~firstclass_MyPoint() {
		if (name != nullptr) {
			delete[] name;
			name = nullptr;
		}
		cout << "Destructor called" << endl;
	}


	const char* getName()const { return (strcmp(name, "") == 0) ? "Point" : name; }
	inline int getX()const { return x; }
	inline int getY()const { return y; } // это аксессоры, которые позволяют получить значения закрытых переменных x и y. Они объявлены как константные методы, что означает, что они не изменяют состояние объекта.
	inline Date getDate()const { return myDate; }

	inline void setName(const char* newName); // это мутаторы, которые позволяют установить значения закрытых переменных name, x и y. Они принимают параметры и изменяют состояние объекта.
	inline void setX(int newX); // объявляем сеттеры в классе
	inline void setY(int newY);
	inline void show()const;
	inline void input();


private:
	char* name{nullptr};
	int x{0};
	int y{0};
	Date myDate{ 0, 0, 0 }; // это закрытые переменные, которые хранят состояние объекта. Они недоступны напрямую из других частей программы.

};

void firstclass_MyPoint::show()const {
	cout << "Name: " << getName() << endl;
	cout << "X: " << getX() << endl;
	cout << "Y: " << getY() << endl;
	myDate.show();
}
void firstclass_MyPoint::input() {
	char buf[T];
	cout << "Enter name: ";		
	cin >> ws;
	cin.getline(buf, T);
	setName(buf);
	cout << "Enter X: ";
	int nx;
	cin >> nx;
	setX(nx);
	cout << "Enter Y: ";
	int ny;
	cin >> ny;
	setY(ny);
	cout << "Enter date: " << endl;
	myDate.input();	
}
void firstclass_MyPoint::setX(int newX) { 
	this->x = newX; }
void firstclass_MyPoint::setY(int newY) { this->y = newY; }


void firstclass_MyPoint::setName(const char* newName) {
	if (strlen(newName) != 0) {
		if (name != nullptr) delete[] name;
		name = new char[strlen(newName) + 1];
		strcpy_s(name, strlen(newName) + 1, newName);
	}
}

firstclass_MyPoint::firstclass_MyPoint(const char* name, int x, int y, Date& date) : 
	name(nullptr), x(x), y(y), myDate(date) {
		cout << "Constructor with parameters and date called" << endl;
}




firstclass_MyPoint::firstclass_MyPoint(const char* name, int x, int y_):
	name(nullptr), x(x), y(y_), myDate{ 0,0,0 } {
	cout << "Constructor with parameters called" << endl;
	this->name = new char[T];
	strcpy_s(this->name, strlen(name) + 1, name);
}

firstclass_MyPoint::firstclass_MyPoint(const firstclass_MyPoint& other) {
	x = other.x;
	y = other.y;
	myDate = other.myDate;
	name = nullptr;
	if (other.name != nullptr) {
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);

	}
}

firstclass_MyPoint::firstclass_MyPoint(const char*name) : 
	firstclass_MyPoint(name, 0, 0) {
	myDate = Date{ 0,0,0 }; 
}

firstclass_MyPoint firstclass_MyPoint::operator=(const firstclass_MyPoint& other) {
	x = other.x;
	y = other.y;
	myDate = other.myDate;
	if (name != nullptr) {
		delete[] name;
		name = nullptr;
	}
	if (other.name != nullptr) {
		name = new char[strlen(other.name) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);


	}
	return *this;
}

string WrapOccurrences(const string& s, const string& sub) {
	string result = s;
	size_t pos = 0;

	while ((pos = result.find(sub, pos)) != string::npos) {
		result.insert(pos, "(");
		result.insert(pos + 1 + sub.length(), ")");
		pos = pos + 1 + sub.length() + 1;
	}
	return result;
}

template<class NewT, int Size>
NewT average( NewT* arr)
{
	
	NewT sum = 0;
	NewT middle_counter = 0;

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];

	}

	middle_counter = (double)sum / size;

	return middle_counter;
}


int main()
{ 
    
    //инкапсуляция - скрытие внутреннего представления объекта. полиморфизм - способность объекта иметь разные формы. наследование - механизм создания новых классов на основе существующих. абстракция - выделение основных характеристик объекта.

	// private public protected - это модификаторы доступа в C++. Они определяют, какие члены класса (переменные и функции) могут быть доступны из других частей программы.
	// private - члены класса доступны только внутри самого класса. public - члены класса доступны из любого места программы. protected - члены класса доступны внутри самого класса и его наследников.
	// конструктор и деструктор - это специальные функции-члены класса, которые вызываются при создании и уничтожении объекта соответственно. Конструктор инициализирует объект, а деструктор освобождает ресурсы, связанные с объектом. 
	// конструктор иницилизатор - это конструктор, который использует список инициализации для установки значений членов класса. Он вызывается перед телом конструктора и позволяет инициализировать константные члены и ссылки.
	// конструктор копирования( по битовому) - это конструктор, который создает новый объект как копию существующего объекта. Он копирует значения всех членов класса из исходного объекта в новый объект. Если не определен явно, компилятор создает его автоматически.
	// оператор присваивания - это оператор, который позволяет присвоить значения одного объекта другому объекту того же класса. Он должен быть определен явно, если класс содержит динамически выделенную память или другие ресурсы.
	// унарные и бинарные операторы - 
	// арефметичные операторы -
	// колекция в с++ -
	// оператор []
	// прототип в с++ -





    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

	int arr1[] = { 7, 8, 9 };
	cout << average<int, 3>(arr1) << endl;

	double arr2[] = { 1.5, 2.5, 3.0 };
	cout << average<double, 3>(arr2) << endl;

}


