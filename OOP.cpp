#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
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
		cout << "Constructor called" << endl;
	}

	firstclass_MyPoint(const char*, int, int) {
		cout << "Constructor with parameters called" << endl;
	}
	firstclass_MyPoint(const char*, int, int, Date);
	~firstclass_MyPoint() {
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






int main()
{ 
    
    //инкапсуляция - скрытие внутреннего представления объекта. полиморфизм - способность объекта иметь разные формы. наследование - механизм создания новых классов на основе существующих. абстракция - выделение основных характеристик объекта.

	// private public protected - это модификаторы доступа в C++. Они определяют, какие члены класса (переменные и функции) могут быть доступны из других частей программы.
	// private - члены класса доступны только внутри самого класса. public - члены класса доступны из любого места программы. protected - члены класса доступны внутри самого класса и его наследников.
	// конструктор и деструктор - это специальные функции-члены класса, которые вызываются при создании и уничтожении объекта соответственно. Конструктор инициализирует объект, а деструктор освобождает ресурсы, связанные с объектом. 
	// конструктор иницилизатор - это конструктор, который использует список инициализации для установки значений членов класса. Он вызывается перед телом конструктора и позволяет инициализировать константные члены и ссылки.
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

	firstclass_MyPoint point1;
	point1.setName("MyPoint");
	point1.setY(T);
	if(point1.getX() == 0) {
		point1.setX(15);
	}

	point1.show();


}


