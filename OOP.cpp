#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <windows.h>
#include <cassert>
using namespace std;


struct fraction_struct {
    int numerator;
    int denominator;

	void print() {
		cout << numerator << "/" << denominator << endl;
	}

	void input() {
		cout << "Enter numerator: ";
		cin >> numerator;
		cout << "Enter denominator: ";
		cin >> denominator;
	}

};


class fraction_class {
    
private:
	fraction_struct fraction;

public:

	


};



int main()
{ 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);




}


