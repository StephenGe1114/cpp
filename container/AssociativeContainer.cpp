//
// Created by 14991 on 2022/6/14.
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
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::list;
using std::set;
using std::map;

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

	// map
	map<int, string, std::greater<int>> cities{
		std::pair<int, string>(1, "北京"),
		std::pair<int, string>(2, "上海"),
		std::make_pair(3, "广州"),
		std::make_pair(4, "深圳"),
		std::make_pair(1, "杭州")
	}; // 初始化列表构造
	display1(cities);
	map<int, string> cities1(cities.begin(), cities.end()); // 迭代器构造
	display1(cities1);
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

	// map与set一样

}

// 修改器
void test2()
{
	// set
	set<int> a{1, 2, 3};
	a.clear();
	cout << "size = " << a.size() << endl;

	auto ret = a.insert(3); // 返回类型为std::pair，second为bool，表示有没有发生插入，
	                             // 如果插入了则first为插入元素的迭代器，如果没有插入，则first为已有元素的迭代器
	if(ret.second) {
		cout << "insert success " <<  *ret.first << endl;
	} else {
		cout << "insert fail" << endl;
	}
	auto iter = ret.first;
	ret = a.insert(3);
	if(ret.second) {
		cout << "insert success " <<  *ret.first << endl;
	} else {
		cout << "insert fail" << endl;
	}
	if(ret.first == iter) {
		cout << *ret.first << endl;
	}
	a.insert({1, 2, 3, 4}); // 初始化列表插入
	set<int> b;
	b.insert(a.begin(), a.end()); // 迭代器插入
	cout << endl;

    ret = a.emplace(3); // 与insert类似，insert的实现就是调用emplace
	if(ret.second) {
		cout << "emplace success " <<  *ret.first << endl;
	} else {
		cout << "emplace fail" << *ret.first << endl;
	}
	cout << endl;

	size_t i = a.erase(3); // 删除给定值，返回删除的元素个数
	cout << i << endl;
	iter = a.find(2);
	iter = a.erase(iter); // 删除给定位置的值，返回其后一个元素的迭代器
	display(a);
	iter = a.erase(a.begin(), a.end()); // 产出迭代器范围的值，返回其后一个元素的迭代器；
	assert(iter == a.end());
	cout << endl;

	set<int> c;
	c.swap(b); // 交换两个容器的内容
	display(c);
	display(b);

	set<int> d{3, 4, 5, 6};
	d.merge(c); // 转移c中d不存在的元素至d中，转移后c发生改变
	display(d);
	display(c);
	cout << endl;

	// map
	map<string, string, std::greater<string>> cities{
		std::pair<string, string>("aa", "北京"),
		std::pair<string, string>("bb", "上海"),
		std::make_pair("cc", "广州"),
		std::make_pair("dd", "深圳"),
		std::make_pair("aa", "杭州")
	};
	display1(cities);
	auto ret1 = cities.insert(std::pair<string, string>("aa", "杭州")); // 返回类型为std::pair，second为bool，表示有没有发生插入，
	                                                                                   // 如果插入了则first为插入元素的迭代器，如果没有插入，则first为已有元素的迭代器
	assert(ret1.second == false);
	if(ret1.second) {
		cout << "insert success " << ret1.first->first << " " << ret1.first->second << endl;
	} else {
		cout << "insert fail " << ret1.first->first << " " << ret1.first->second << endl;
	}
	display1(cities);
	map<string, string, std::greater<string>> cities1;
	cities1.insert(cities.begin(), cities.end()); // 迭代器插入
	display1(cities1);
	cities1.insert({{"ff", "南京"}, {"ee", "扬州"}}); // 初始化列表插入
	display1(cities1);

	cities1.clear();
	cout << "size = " << cities1.size() << endl;

	cities1.emplace(std::make_pair("aa", "北京"));
	display1(cities1);

	// 同set
}

// 查找
void test3()
{
	// set
	set<int> a{1, 2, 3, 4};
	size_t i = a.count(2); // 返回指定值的数量

	auto iter = a.find(3); // 返回指定值的迭代器，若找不到返回尾后迭代器
	cout << *iter << endl;

	auto ret = a.equal_range(2); // 返回容器中所有拥有给定关键的元素范围。范围以二个迭代器定义，
	                                    // 一个指向首个不小于 key 的元素，另一个指向首个大于 key 的元素(顺序情况下)
										// 一个指向首个不大于key的元素，另一个指向首个小于key的元素（逆序情况）
										// 首个迭代器可以换用 lower_bound() 获得，而第二迭代器可换用 upper_bound() 获得
    cout << *ret.first << " " << *ret.second << endl;
	set<int, greater<int>> b{1, 2, 3, 5, 6};
	ret = b.equal_range(4);
	cout << *ret.first << " " << *ret.second << endl;

	cout << *b.lower_bound(4) << *b.upper_bound(4) << endl; // 见equal_range

	// map
	map<string, string, std::greater<string>> cities{
		std::pair<string, string>("aa", "北京"),
		std::pair<string, string>("bb", "上海"),
		std::make_pair("cc", "广州"),
		std::make_pair("dd", "深圳"),
		std::make_pair("aa", "杭州")
	};
	auto iter1 = cities.find("aa");
	if(iter1 != cities.end()) {
		cout << iter1->second << endl;
	}
	iter1 = cities.find("zz");
	if(iter1 != cities.end()) {
		cout << "have" << endl;
	} else {
		cout << "don't have" << endl;
	}

	// 其余与set一样
}

// 元素访问
void test4()
{
	map<int, string, std::greater<int>> cities{
		std::pair<int, string>(1, "北京"),
		std::pair<int, string>(2, "上海"),
		std::make_pair(3, "广州"),
		std::make_pair(4, "深圳"),
		std::make_pair(1, "杭州")
	};
	cities.at(1) = "南京"; // 返回到拥有等于 key 的关键的元素被映射值的引用，若无这种元素，则抛出 std::out_of_range 类型异常
	display1(cities);
	cities[1] = "北京"; // 返回到映射到等于 key 的键的值的引用，若这种键不存在则进行插入
	display1(cities);
}

void test5()
{

}

int main()
{
//    test0();
//    test1();
//    test2();
    test3();
//    test4();
//	test5();

	return 0;
}

