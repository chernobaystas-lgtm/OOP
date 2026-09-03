#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <windows.h>
#include <cassert>
using namespace std;

#define T 100
class Entity {
protected:
    static void copy_field2(char*& dst, const char* src) {
        delete[] dst;
        dst = new char[T];
        if (src != nullptr) {
            strcpy_s(dst, T, src);
        }
        else {
            dst[0] = '\0';
        }
    }
};

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


class fraction_class : public Entity {
    
private:
	fraction_struct fraction;

public:


    // --- Конструктор за замовчуванням ---
    fraction_class() : fraction() {
        fraction = { 0, 0 };
    }



    // --- Повний параметризований конструктор ---
    fraction_class(fraction_struct n) : fraction() {
    }


    // --- Конструктор копіювання ---
    fraction_class(const fraction_class& other) : fraction(other.fraction) {
    }

    // --- Оператор присвоєння (копіювання) ---
    fraction_class& operator=(const fraction_class& other) {
        if (this == &other) return *this;
        fraction = other.fraction;
        return *this;
    }


    // --- Move-присвоєння ---
    fraction_class& operator=(fraction_class&& other) noexcept {
        if (this == &other) return *this;
        fraction = other.fraction;
        other.fraction = {};
        return *this;
    }



};



int main()
{ 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);




}


