#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <windows.h>
#include <cassert>
using namespace std;

#define T 100


struct flat_struct {
    double area;
    int rooms;
    double pricePerMeter;
};

class flat_class {
private:
    flat_struct flat;

public:
    flat_class() : flat() {
        flat = { 0, 0, 0 };
    }

    flat_class(flat_struct f) : 
        flat(f) {}

    flat_class(const flat_class& other) :
        flat(other.flat) {}

    flat_class& operator=(const flat_class& other) {
        if (this == &other) return *this;
        flat = other.flat;
        return *this;
    }

    bool operator==(const flat_class& other) const {
        return flat.area == other.flat.area;
    }

    bool operator!=(const flat_class& other) const {
        return !(*this == other);
    }

    flat_class& operator++() {
        flat.rooms++;
        return *this;
    }

    flat_class& operator--() {
        flat.rooms--;
        return *this;
    }

    double GetTotalPrice() const {
        return flat.area * flat.pricePerMeter;
    }

    bool operator>(const flat_class& other) const {
        return GetTotalPrice() > other.GetTotalPrice();
    }

    bool operator<(const flat_class& other) const {
        return GetTotalPrice() < other.GetTotalPrice();
    }

    friend istream& operator>>(istream& in, flat_class& obj);
    friend ostream& operator<<(ostream& out, const flat_class& obj);
};

istream& operator>>(istream& in, flat_class& obj) {
    cout << "Введіть площу: ";
    in >> obj.flat.area;
    cout << "Введіть кількість кімнат: ";
    in >> obj.flat.rooms;
    cout << "Введіть ціну за квадратний метр: ";
    in >> obj.flat.pricePerMeter;
    return in;
}

ostream& operator<<(ostream& out, const flat_class& obj) {
    out << "Площа: " << obj.flat.area << " м2, Кімнат: " << obj.flat.rooms
        << ", Ціна за м2: " << obj.flat.pricePerMeter
        << ", Загальна ціна: " << obj.GetTotalPrice();
    return out;
}


int main()
{ 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    flat_class f1(flat_struct{ 50.0, 2, 1000.0 });
    flat_class f2(flat_struct{ 50.0, 3, 1200.0 });

    cout << (f1 == f2) << endl; // 1, площади равны (50==50)
    cout << (f1 > f2) << endl;  // 0, у f1 общая цена меньше

    ++f1;
    cout << f1 << endl; // комнат стало 3

}


