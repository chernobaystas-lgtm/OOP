#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;

#define T 30

struct Date {
	int day;
	int month;
	int year;

	void input() {
		cout << "Enter day: ";
		cin >> day;
		cout << "Enter month: ";
		cin >> month;
		cout << "Enter year: ";
		cin >> year;
	}

	void output() {
		cout << day << "/" << month << "/" << year;
	}
};

class book {
private:
	char* author{ nullptr };
	char* title{ nullptr };
	char* publishing{ nullptr };
	char* annotation{ nullptr };
	int year{ 0 };
	int counter{ 0 };
	int pages{ 0 };
	int annotation{ 0 };
public:



};





int main()
{ 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);





    return 0;


}


