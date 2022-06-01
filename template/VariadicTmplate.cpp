//
// Created by 14991 on 2022/5/27.
//

#include <iostream>
using std::cout;
using std::endl;

template <typename... Args>
void display(Args... args)
{
    cout << sizeof...(Args) << endl;
    cout << sizeof...(args) << endl;
}

int test0()
{
    int a = 1;
    double b = 2.2;
    std::string s = "hello,world";
    display(a, b, s, 'A');

    return 0;
}

void print()
{
    cout << "end" << endl;
}

template <typename T>
void print(T t)
{
    cout << t << endl;
}

template <typename T, typename... Args>
void print(T t, Args... args)
{
    cout << t << endl;
    print(args...);
}

void test1()
{
    int a = 1;
    double b = 2.2;
    std::string s = "hello,world";
    print(a, b, s, 'A');
}

template <typename T>
T sum(T t)
{
    return t;
}

template <typename T, typename... Args>
T sum(T t, Args... args)
{
    return t += sum(args...);
}

void test2(void)
{
    cout << sum(1, 2, 3, 4) << endl;
    //return 1 += sum(2, 3, 4);
    //return 1 += (2 += sum(3, 4))
    //return 1 += (2 += (3 += sum(4)))
    //return 1 += (2 += (3 += 4))
}

int main()
{
//    test0();
//    test1();
    test2();

    return 0;
}

