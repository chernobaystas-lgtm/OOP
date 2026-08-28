#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
using namespace std;

#define T 20
#define PI 3.14



class Airplane
{
private:
    char type;
    int passengers;

public:

    Airplane(char t, int p)
    {
        type = t;
        passengers = p;
    }

    bool operator==(const Airplane& other)
    {
        return type == other.type;
    }

    bool operator!=(const Airplane& other)
    {
        return type != other.type;
    }

    bool operator>(const Airplane& other)
    {
        return passengers > other.passengers;
    }

    bool operator<(const Airplane& other)
    {
        return passengers < other.passengers;
    }

    // префиксная форма ++самолёт
    Airplane& operator++()
    {
        passengers = passengers + 1;
        return *this;
    }

    // постфиксная форма самолёт++
    Airplane operator++(int)
    {
        Airplane old = *this;
        passengers = passengers + 1;
        return old;
    }

    // префиксная форма --самолёт
    Airplane& operator--()
    {
        passengers = passengers - 1;
        return *this;
    }

    // постфиксная форма самолёт--
    Airplane operator--(int)
    {
        Airplane old = *this;
        passengers = passengers - 1;
        return old;
    }

    int getPassengers()
    {
        return passengers;
    }

    char getType()
    {
        return type;
    }
};


int main()
{ 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Airplane a('A', 150);
    Airplane b('B', 200);
    Airplane c('A', 150);

    cout << "a == b: " << (a == b) << endl;
    cout << "a == c: " << (a == c) << endl;
    cout << "a != b: " << (a != b) << endl;

    cout << "a > b: " << (a > b) << endl;
    cout << "a < b: " << (a < b) << endl;

    cout << "--- postfix a++ ---" << endl;
    Airplane old = a++;
    cout << "old (до увеличения): " << old.getPassengers() << endl;
    cout << "a (после увеличения): " << a.getPassengers() << endl;

    cout << "--- prefix ++a ---" << endl;
    ++a;
    cout << "a: " << a.getPassengers() << endl;

    cout << "--- postfix a-- ---" << endl;
    Airplane old2 = a--;
    cout << "old2 (до уменьшения): " << old2.getPassengers() << endl;
    cout << "a (после уменьшения): " << a.getPassengers() << endl;

    cout << "--- prefix --a ---" << endl;
    --a;
    cout << "a: " << a.getPassengers() << endl;

    return 0;
}


