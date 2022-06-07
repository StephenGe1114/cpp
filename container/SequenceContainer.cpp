//
// Created by 14991 on 2022/5/26.
//

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::deque;
using std::list;

template <typename Container>
void display(const Container& c)
{
    for(auto m: c) {
        cout << m << ' ';
    }
    cout << endl;
}

void test0()
{
    // vector构造函数
    vector<char> vec1(3, 'a');
    display(vec1);
    vector<string> vec2{"beijing", "shanghai", "shenzhen", "nanjing"};
    display(vec2);
    vector<string> vec3(vec2.begin(), vec2.end());
    display(vec3);
    vector<string> vec4(vec3);
    display(vec4);
    cout << endl;

    // assign，替换容器的内容
    vec4.assign(3, "a");
    display(vec4);
    vec4.assign(vec2.begin(), vec2.end());
    display(vec4);
    vec4.assign({"c++", "11"});
    display(vec4);
    cout << endl;

    // 元素访问
    vector<int> vec5{1, 2, 3, 4, 5, 6};
    vec5.at(1) = 88; // at函数返回位于指定位置 pos 的元素的引用，有边界检查。
    try {
        vec5.at(6) = 66;
    } catch (std::out_of_range const& exc) {
        std::cout << exc.what() << '\n';
    }
    vec5[5] = 55;
    vec5.front() = 11; // front函数返回首元素的引用。
    vec5.back() = 66; // back函数返回最后元素的引用。
    display(vec5);
    cout << endl;

    // 迭代器
    for(auto it = vec5.begin(); it != vec5.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    for(auto it = vec5.rbegin(); it != vec5.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 容量
    if(!vec5.empty()) {
        cout << "size = " << vec5.size() << endl; // 返回容器中的元素数
        cout << "capacity = " << vec5.capacity() << endl; // 返回容器当前已为之分配空间的元素数
        vec5.reserve(10); // 若参数大于capacity，则增加vector的capacity，且所有迭代器失效；反之什么也不做；
        cout << "size = " << vec5.size() << endl;
        cout << "capacity = " << vec5.capacity() << endl;
        vec5.reserve(5);
        cout << "size = " << vec5.size() << endl;
        cout << "capacity = " << vec5.capacity() << endl;
        auto it = vec5.begin();
        cout << "before shrink_to_fit " << *it << endl;
        vec5.shrink_to_fit(); // 当capacity大于size时，使capacity与size值一样，且所有迭代器失效；反之什么也不做。
//        cout << "after shrink_to_fit " << *it << endl;
        cout << "size = " << vec5.size() << endl;
        cout << "capacity = " << vec5.capacity() << endl;
        cout << endl;
    }

    // 修改器
    auto it = vec5.begin();
    cout << "before clear " << *it << endl;
    vec5.clear(); // 擦除容器所有元素，此后size为0，capacity不变，迭代器失效
//    *it = 999;
//    cout << "after clear " << *it << endl;
    cout << "size = " << vec5.size() << endl;
    cout << "capacity = " << vec5.capacity() << endl;

    vector<string> svec{"beijing", "shanghai", "guangzhou", "shenzheng"};
    svec.insert(svec.begin(), "zhongguo"); // 在给定位置前插入，返回被插入元素的迭代器
    display(svec);
    auto it1 = svec.insert(svec.begin(), 3, "aaa"); // 在给定位置前插入n个，返回被插入元素首元素的迭代器
    cout << *(it1 + 3) << endl;
    display(svec);
    vector<string> svec1{"bb", "cc"};
    it1 = svec.insert(svec.end(), svec1.begin(), svec1.end()); // 通过迭代器插入给定位置前，返回被插入元素首元素的迭代器
    cout << *(it1 + 1) << endl;
    display(svec);
    it1 = svec.insert(svec.end(), {"dd", "ee", "ff"});
    cout << *(it1 + 2) << endl;
    display(svec);

    vector<string> svec2{"aa", "bb", "cc"};
    it1 = svec2.emplace(svec2.begin() + 1, "dd"); // 在给定位置前插入元素，返回被插入元素的迭代器
    cout << *it1 << endl;
    display(svec2);
    cout << endl;

    it1 = svec2.erase(svec2.begin()); // 删除指定的元素，返回后一元素的迭代器；
    cout << *it1 << endl;
    display(svec2);
    it1 = svec2.erase(svec2.begin() + 1, svec2.begin() + 2); // 移除[first, last)中的元素，不包含last，返回删除元素的后一元素的迭代器；
    cout << *it1 << endl;
    display(svec2);

    svec2.push_back("ff"); // 将元素添加到容器末尾
    display(svec2);

    auto ref = svec2.emplace_back("gg"); // 将元素添加到容器末尾，返回该元素的引用
    cout << ref << endl;
    display(svec2);

    svec2.pop_back(); // 移除容器的末元素
    display(svec2);
    cout << endl;

    cout << svec2.size() << endl;
    cout << svec2.capacity() << endl;
    svec2.resize(2);
    cout << svec2.size() << endl;
    cout << svec2.capacity() << endl;
    display(svec2);
    cout << endl;
    svec2.resize(7, "hh"); // 重置容器size为count个，若count小于容器size，则减小容器为其首count个元素；若count大于容器size，则超过的部分调用元素的默认构造函数构造或者用指定的值构造；
    cout << svec2.size() << endl;
    cout << svec2.capacity() << endl;
    display(svec2);
    cout << endl;

    vector<int> v{1, 2, 3, 4};
    vector<int> v1{5, 6, 7};
    auto it2 = v.begin();
    v.swap(v1); // 互换两个容器的内容
    display(v);
    display(v1);
    for(; it2 != v1.end(); ++it2) {
        cout << *it2 << " ";
    }
    cout << endl;
}

int main()
{
    test0();
    return 0;
}

