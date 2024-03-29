 ///
 /// @file    nestClass.cc
 /// @author  gsw(1499186594@qq.com)
 ///
   

#include "nestClass.h"
#include <iostream>
using std::cout;
using std::endl;

// 使用嵌套类的原因：
// 1. 不希望嵌套类被直接访问, 实现信息的隐藏
// 2. 嵌套类只为外部类服务

class Line::LineImpl // 外部类
{
	class Point // 内部类
	{
	public:
		Point(int ix = 0, int iy = 0)
			: _ix(ix), _iy(iy)
		{
			cout << "Point(int,int) " << endl;
		}

		void print() const
		{
			cout << "(" << _ix
				 << "," << _iy
				 << ")";
		}

		~Point()
		{
			cout << "~Point()" << endl;
		}

	private:
		int _ix;
		int _iy;
	};

public:
	LineImpl(int x1, int y1, int x2, int y2)
		: _pt1(x1, y1), _pt2(x2, y2)
	{
		cout << "LineImpl(int,int,int,int)" << endl;
	}

	void printLine() const
	{
		_pt1.print();
		cout << " ---> ";
		_pt2.print();
		cout << endl;
	}

	~LineImpl()
	{
		cout << "~LineImpl()" << endl;
	}

private:
	Point _pt1;
	Point _pt2;
};

Line::Line(int x1, int y1, int x2, int y2)
	: _pimpl(new LineImpl(x1, y1, x2, y2))
{
	cout << "Line(int, int,int,int)" << endl;
}

void Line::printLine() const
{
	_pimpl->printLine();
}

Line::~Line()
{
	cout << "~Line()" << endl;
	delete _pimpl;
}

int main(void)
{
	// Line::Point pt1(1, 2);
	// pt1.print();
	// cout << endl;

	Line line(1, 2, 3, 4);
	line.printLine();

	return 0;
}

