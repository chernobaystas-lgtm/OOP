#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
using namespace std;

#define T 20
#define PI 3.14



class Circle
{
private:
    double radius;

public:

    Circle(double r)
    {
        radius = r;
    }


    bool operator==(const Circle& other)
    {
        return radius == other.radius;
    }

    bool operator!=(const Circle& other)
    {
        return radius != other.radius;
    }

    bool operator<(const Circle& other)
    {
        double length1 = 2 * PI * radius;
        double length2 = 2 * PI * other.radius;

        return length1 < length2;
    }


    bool operator>(const Circle& other)
    {
        double length1 = 2 * PI * radius;
        double length2 = 2 * PI * other.radius;

        return length1 > length2;
    }

    bool operator<=(const Circle& other)
    {
        double length1 = PI * radius * radius;
        double length2 = PI * other.radius * other.radius;

        return length1 <= length2;
    }

    bool operator>=(const Circle& other)
    {
        double area1 = PI * radius * radius;
        double area2 = PI * other.radius * other.radius;

        return area1 >= area2;
    }

    Circle& operator+=(double value)
    {
        radius = radius + value;
        return *this;
    }


    Circle& operator-=(double value)
    {
        radius = radius - value;
        return *this;
    }


    Circle operator+(const Circle& other)
    {
        double newRadius;

        if (radius < other.radius)
        {
            newRadius = other.radius + radius / 2;
        }
        else
        {
            newRadius = radius + other.radius / 2;
        }

        return Circle(newRadius);
    }

    double getRadius()
    {
        return radius;
    }
};



int main()
{ 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Circle a(5);
    Circle b(10);

    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a >= b: " << (a >= b) << endl;

    a += 3;
    cout << "a after += 3: " << a.getRadius() << endl;

    a -= 2;
    cout << "a after -= 2: " << a.getRadius() << endl;

    Circle c = a + b;
    cout << "c = a + b, radius: " << c.getRadius() << endl;

    return 0;

}


