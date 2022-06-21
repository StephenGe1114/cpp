//
// Created by 14991 on 2022/6/14.
//

#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::list;
using std::set;

template<typename Container>
void display(const Container &c)
{
	for (auto m: c) {
		cout << m << ' ';
	}
	cout << endl;
}

template <typename T>
struct greater
{
	bool operator()(const T& lhs, const T& rhs) const
	{
		return lhs > rhs;
	}

};

class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix), _iy(iy)
	{}

	friend bool operator<(const Point& lhs, const Point& rhs);
	friend bool operator>(const Point& lhs, const Point& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Point& rhs);
private:
	int _ix;
    int _iy;
};

bool operator<(const Point &lhs, const Point &rhs)
{
	return sqrt(lhs._ix * lhs._ix + lhs._iy * lhs._iy)
		< sqrt(rhs._ix * rhs._ix + rhs._iy * rhs._iy);
}

bool operator>(const Point &lhs, const Point &rhs)
{
	return sqrt(lhs._ix * lhs._ix + lhs._iy * lhs._iy)
		> sqrt(rhs._ix * rhs._ix + rhs._iy * rhs._iy);
}

std::ostream& operator<<(std::ostream& os, const Point& rhs)
{
	os << "(" << rhs._ix << ", " << rhs._iy << ")";
	return os;
}

// 构造函数
void test0()
{
	// set
	{
		set<int> a{5, 4, 3, 2, 7}; // 初始化列表
		display(a);

		set<int, greater<int>> b{1, 2, 3, 4};
		display(b);

		set<int, greater<int>> c(std::move(b)); // 移动构造
		display(c);

		set<int, greater<int>> d(c); // 复制构造
		display(d);

		set<int> e(a.begin(), a.end()); // 迭代器构造
		display(e);

		set<Point> f{{1, 2}, {3, 4}, {2, 3}, {0, 1}};
		display(f);

		set<Point, greater<Point>> g{{1, 2}, {3, 4}, {2, 3}, {0, 1}};
		display(g);
		cout << endl;
	}
}

// 容量
void test1()
{
	// set
	set<int> a;
	if (a.empty()) { //
		cout << "empty" << endl;
	}
	set<int> b{1, 2};
	cout << "size = " << b.size() << endl; //
	cout << endl;

}

// 修改器
void test2()
{
	// set
	set<int> a{1, 2, 3};
	a.clear();
	cout << "size = " << a.size() << endl;

	auto ret = a.insert(3);
	if(ret.second) {
		cout << "insert success " <<  *ret.first << endl;
	}

}

void test3()
{

}

void test4()
{

}

void test5()
{

}

int main()
{
    test0();
    test1();
    test2();
    test3();
    test4();
	test5();

	return 0;
}

