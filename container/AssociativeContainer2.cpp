//
// Created by 14991 on 2022/6/22.
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

template<typename Container>
void display(const Container &c)
{
	for (auto m: c) {
		cout << m << ' ';
	}
	cout << endl;
}

template <typename Container>
void display1(const Container & c)
{
	typename Container::const_iterator it;
	for(it = c.begin(); it != c.end(); ++it)
	{
		cout << it->first << " --> " << it->second << endl;
	}
	cout << endl;
}

class Point
{
public:
	Point(int ix, int iy)
		: _ix(ix), _iy(iy)
	{}

	int getX() const
	{ return _ix; }

	int getY() const
	{ return _iy; }

	friend bool operator<(const Point& lhs, const Point& rhs);
	friend bool operator>(const Point& lhs, const Point& rhs);
	friend bool operator==(const Point& lhs, const Point& rhs);

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

bool operator==(const Point& lhs, const Point& rhs)
{
	return sqrt(lhs._ix * lhs._ix + lhs._iy * lhs._iy)
		== sqrt(rhs._ix * rhs._ix + rhs._iy * rhs._iy);
}

std::ostream& operator<<(std::ostream& os, const Point& rhs)
{
	os << "(" << rhs._ix << ", " << rhs._iy << ")";
	return os;
}

void test0()
{
	unordered_set<int> sets{5, 3, 2, 1, 3, 2, 8, 0, 9};
	display(sets);
}

namespace std
{
template <>
struct hash<Point>
{
	size_t operator()(const Point & lhs) const
	{
		return (std::hash<int>()(lhs.getX()) << 1)
			^ (std::hash<int>()(lhs.getY()) >> 1);
	}
};
}

struct PointHasher
{
	size_t operator()(const Point & lhs) const
	{
		return (std::hash<int>()(lhs.getX()) << 1)
			^ (std::hash<int>()(lhs.getY()) >> 1);
	}
};

void test1(void)
{
	unordered_set<Point> sets{
		Point(1, 2),
		Point(3, 4),
		Point(1, 2),
		Point(5, 6)
	};
	display(sets);
}

void test2(void)
{
	unordered_set<Point, PointHasher> sets{
		Point(1, 2),
		Point(3, 4),
		Point(1, 2),
		Point(5, 6)
	};
	display(sets);

}

int main()
{
//    test0();
    test1();
//    test2();
//	test3();
//    test4();
//	test5();

	return 0;
}
