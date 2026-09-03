#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <windows.h>
#include <cassert>
using namespace std;

#define T 100


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


class fraction_class{
    
private:
	fraction_struct fraction;

public:
    // --- Конструктор за замовчуванням ---
    fraction_class() : fraction() {
        fraction = { 0, 0 };
    }



    // --- Повний параметризований конструктор ---
    fraction_class(fraction_struct n) : fraction(n) {
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

    fraction_class operator+(const fraction_class& other) {
        fraction_struct result;
        result.numerator = fraction.numerator * other.fraction.denominator + other.fraction.numerator * fraction.denominator;
        result.denominator = fraction.denominator * other.fraction.denominator;
        return fraction_class(result);
    }
    fraction_class operator-(const fraction_class& other) {
        fraction_struct result;
        result.numerator = fraction.numerator * other.fraction.denominator - other.fraction.numerator * fraction.denominator;
        result.denominator = fraction.denominator * other.fraction.denominator;
        return fraction_class(result);
    }
    fraction_class operator*(const fraction_class& other) {
        fraction_struct result;
        result.numerator = fraction.numerator * other.fraction.numerator;
        result.denominator = fraction.denominator * other.fraction.denominator;
        return fraction_class(result);
    }
    fraction_class operator/(const fraction_class& other) {
        fraction_struct result;
        result.numerator = fraction.numerator * other.fraction.denominator;
        result.denominator = fraction.denominator * other.fraction.numerator;
        return fraction_class(result);
    }

    bool operator==(const fraction_class& other) const {
        return fraction.numerator * other.fraction.denominator == other.fraction.numerator * fraction.denominator;
    }

    bool operator!=(const fraction_class& other) const {
        return !(*this == other);
    }

    bool operator<(const fraction_class& other) const {
        return fraction.numerator * other.fraction.denominator < other.fraction.numerator * fraction.denominator;
    }

    bool operator>(const fraction_class& other) const {
        return fraction.numerator * other.fraction.denominator > other.fraction.numerator * fraction.denominator;
    }
};



int main()
{ 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    fraction_class a(fraction_struct{ 1, 2 });
    fraction_class b(fraction_struct{ 1, 3 });

    cout << (a == b) << endl; // 0, не равны
    cout << (a > b) << endl;  // 1, 1/2 > 1/3

}


