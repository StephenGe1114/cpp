//
// Created by 14991 on 2022/6/6.
//

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Point
{
public:
    Point(int x, int y)
    : _x(x), _y(y)
    {}

    void display()
    {
        cout << "x = " << _x << " y = " << _y << endl;
    }

    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
    int _x;
    int _y;
};

class Computer
{
public:
    Computer(int price, const char* name)
    : _price(price), _name(new char[strlen(name) + 1]())
    {
        strcpy(_name, name);
    }

    void display()
    {
        cout << "price = " << _price << " name = " << _name << endl;
    }

    ~Computer()
    {
        cout << "~Computer()" << endl;
        delete _name;
    }
private:
    int _price;
    char* _name;
};

template <typename T>
class Singleton
{
public:
    template <typename... Args>
    static T* getInstance(Args... args)
    {
        if(!_pInstance) {
            _ar;
            _pInstance = new T(args...);
        }
        return _pInstance;
    }
private:
    class AutoRelease
    {
    public:
        AutoRelease()
        {
            cout << "AutoRelease()" << endl;
        }

        ~AutoRelease()
        {
            cout << "~AutoRelease()" << endl;
            if(_pInstance) {
                delete _pInstance;
            }
        }
    };
private:
    Singleton() { cout << "Singleton()" << endl; }
    ~Singleton() { cout << "~Singleton()" << endl; }
private:
    static T* _pInstance;
    static AutoRelease _ar;
};

template <typename T>
T* Singleton<T>::_pInstance;

template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_ar;

int main()
{
    Point* point = Singleton<Point>::getInstance(3, 4);
    point->display();

    Computer* computer = Singleton<Computer>::getInstance(9999, "HuaWei");
    computer->display();

    return 0;
}