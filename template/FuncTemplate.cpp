//
// Created by 14991 on 2022/5/27.
//

#include <string.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T>
T add(T x, T y)
{
    return x + y;
}

template <>
const char* add(const char* x, const char* y)
{
    char* ptmp = new char[strlen(x) + strlen(y) + 1]();
    strcpy(ptmp, x);
    strcat(ptmp, y);
    return ptmp;
}

template <typename T>
T add(T x, T y, T z)
{
    return x + y + z;
}

template <typename T, int kSize = 10>
T multiply(T x, T y)
{
    return x * y * kSize;
}

int test0()
{
    int a = 3, b = 4, c = 5;
    double d1 = 11.11, d2 = 22.22;
    char c1 = 'A', c2 = 1;
    string s1 = "hello";
    string s2 = "world";

    const char* p1 = "hello";
    const char* p2 = "world";

    cout << "add(a, b) = " << add(a, b) << endl;
    cout << "add(d1, d2) = " << add<double>(d1, d2) << endl;
    cout << "add(c1, c2) = " << add(c1, c2) << endl;
    cout << "add(a, b, c) = " << add(a, b, c) << endl;
    cout << "add(s1, s2) = " << add(s1, s2) << endl;
    cout << "add(p1, p2) = " << add(p1, p2) << endl;
    cout << endl;

    cout << "multiply(a, b) = " << multiply<int, 5>(a, b) << endl;
    cout << multiply(a, b) << endl;

    return 0;
}

class Point
{
public:
    Point(double dx = 0, double dy = 0)
    : _dx(dx), _dy(dy)
    {}

    template <typename T>
    T typeCast()
    {
        return (T) _dx * _dy;
    }
private:
    double _dx;
    double _dy;
};

void test1()
{
    Point pt(1.1, 3.2);
    cout << pt.typeCast<int>() << endl;
}

int main()
{
//    test0();
    test1();

    return 0;
}