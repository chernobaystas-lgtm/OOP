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
    char name[50];
    int maxPassengers;
    int minPassengers;
    int occupied;
    char from[50];
    char to[50];

public:

    Airplane(const char n[], int maxP, int minP, int occ, const char f[], const char t[])
    {
        int i = 0;
        while (n[i] != '\0')
        {
            name[i] = n[i];
            i = i + 1;
        }
        name[i] = '\0';

        maxPassengers = maxP;
        minPassengers = minP;
        occupied = occ;

        int j = 0;
        while (f[j] != '\0')
        {
            from[j] = f[j];
            j = j + 1;
        }
        from[j] = '\0';

        int k = 0;
        while (t[k] != '\0')
        {
            to[k] = t[k];
            k = k + 1;
        }
        to[k] = '\0';
    }

    Airplane()
    {
        name[0] = '\0';
        maxPassengers = 0;
        minPassengers = 0;
        occupied = 0;
        from[0] = '\0';
        to[0] = '\0';
    }

    bool operator==(const Airplane& other)
    {
        int i = 0;
        while (name[i] != '\0' && other.name[i] != '\0')
        {
            if (name[i] != other.name[i])
            {
                return false;
            }
            i = i + 1;
        }
        return name[i] == other.name[i];
    }

    bool operator!=(const Airplane& other)
    {
        return !(*this == other);
    }

    bool operator>(const Airplane& other)
    {
        return maxPassengers > other.maxPassengers;
    }

    bool operator<(const Airplane& other)
    {
        return maxPassengers < other.maxPassengers;
    }

    Airplane& operator++()
    {
        occupied = occupied + 1;
        return *this;
    }

    Airplane operator++(int)
    {
        Airplane old = *this;
        occupied = occupied + 1;
        return old;
    }

    Airplane& operator--()
    {
        occupied = occupied - 1;
        return *this;
    }

    Airplane operator--(int)
    {
        Airplane old = *this;
        occupied = occupied - 1;
        return old;
    }

    int getOccupied()
    {
        return occupied;
    }

    int getMax()
    {
        return maxPassengers;
    }
};


int main()
{
    Airplane a("Boeing737", 180, 50, 100, "Kyiv", "Warsaw");
    Airplane b("AirbusA320", 150, 40, 90, "Lviv", "Berlin");
    Airplane c("Boeing737", 180, 50, 100, "Kyiv", "Warsaw");

    cout << "a == b: " << (a == b) << endl;
    cout << "a == c: " << (a == c) << endl;
    cout << "a != b: " << (a != b) << endl;

    cout << "a > b: " << (a > b) << endl;
    cout << "a < b: " << (a < b) << endl;

    cout << "--- postfix a++ ---" << endl;
    Airplane old = a++;
    cout << "old occupied: " << old.getOccupied() << endl;
    cout << "a occupied: " << a.getOccupied() << endl;

    cout << "--- prefix ++a ---" << endl;
    ++a;
    cout << "a occupied: " << a.getOccupied() << endl;

    cout << "--- postfix a-- ---" << endl;
    Airplane old2 = a--;
    cout << "old2 occupied: " << old2.getOccupied() << endl;
    cout << "a occupied: " << a.getOccupied() << endl;

    cout << "--- prefix --a ---" << endl;
    --a;
    cout << "a occupied: " << a.getOccupied() << endl;

    return 0;
}

