#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
using namespace std;

#define T 20

class firstclass_MyPoint {

public: 
	const char* getName()const { return (strcmp(name, "") == 0) ? "Point" : name; }
	int getX()const { return x; }
	int getY()const { return y; } // это аксессоры, которые позволяют получить значения закрытых переменных x и y. Они объявлены как константные методы, что означает, что они не изменяют состояние объекта.

	void setName(const char* newName) { strncpy_s(name, T, newName, T - 1); name[T - 1] = '\0'; } // это мутаторы, которые позволяют установить значения закрытых переменных name, x и y. Они принимают параметры и изменяют состояние объекта.
	void setX(int newX); // объявляем сеттеры в классе
	void setY(int newY);
	void show()const;
	void input();

private:
	char name[T]{"Point"};
	int x{0};
	int y{0};

};

void firstclass_MyPoint::show()const {
	cout << "Name: " << getName() << endl;
	cout << "X: " << getX() << endl;
	cout << "Y: " << getY() << endl;
	cout << "Date" << 
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
}
void firstclass_MyPoint::setX(int newX) { 
	this->x = newX; }
void firstclass_MyPoint::setY(int newY) { this->y = newY; }

struct firstclass_MyPoint1 {
    char name[T]{"Point"};
    int x{0};
    int y{0};

};

int main()
{ 
    
    //инкапсуляция - скрытие внутреннего представления объекта. полиморфизм - способность объекта иметь разные формы. наследование - механизм создания новых классов на основе существующих. абстракция - выделение основных характеристик объекта.

	// private public protected - это модификаторы доступа в C++. Они определяют, какие члены класса (переменные и функции) могут быть доступны из других частей программы.
	// private - члены класса доступны только внутри самого класса. public - члены класса доступны из любого места программы. protected - члены класса доступны внутри самого класса и его наследников.
	// конструктор и деструктор - это специальные функции-члены класса, которые вызываются при создании и уничтожении объекта соответственно. Конструктор инициализирует объект, а деструктор освобождает ресурсы, связанные с объектом. 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

	firstclass_MyPoint point1;
	point1.setName("MyPoint");
	point1.setY(T);
	if(point1.getX() == 0) {
		point1.setX(15);
	}

	point1.show();

	firstclass_MyPoint1 point2;
    point2.x = 10;



}


