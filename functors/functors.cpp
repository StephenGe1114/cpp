//
// Created by 14991 on 2022/6/28.
//

#include <cmath>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::list;
using std::set;
using std::map;
using std::unordered_set;
using std::unordered_map;
using std::function;
using std::bind;

struct Add
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int add(int a, int b)
{
	return a + b;
}

typedef int (*Function)(int, int);

// 函数对象的五种形式
void test0()
{
	// 1.重载了“（）”操作符的普通类对象
	Add a;
	cout << a(3, 4) << endl;

	// 2.函数名
	cout << add(3, 5) << endl;

	// 3.指向函数的指针
	Function f = add;
	cout << f(4, 6) << endl;

	// 4.lambda表达式
	function<int(int, int)> f1 = [](int a, int b) {
		return a + b;
	};
	cout << f1(7, 8) << endl;

	// 5.bind创建的对象
	auto f2 = bind(add, 9, std::placeholders::_3);
	cout << f2(3, 8, 7) << endl; // 值为16

}

int d = 6;
// lambda表达式
void test1()
{
	auto f = []() {
		cout << "hello" << endl;
	};
	f();

	static int c = 9;
	int a = 4;
	auto f1 = [&a](int b) {
		a = 1;
		c = 1;
		d = 1;
		return a + b + c + d;
	};
	cout << f1(2) << endl;
	cout << a << " c = " << c << " d = " << d << endl;

}

// bind
void test2()
{

}

int main()
{
//	test0();
	test1();
//	test2();
	return 0;
}


