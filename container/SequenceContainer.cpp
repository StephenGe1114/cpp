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

// 构造函数
void test0()
{
    // vector常用的4种构造方式
    vector<char> vec1(3, 'a'); // 1
    display(vec1);
    vector<string> vec2{"beijing", "shanghai", "shenzhen", "nanjing"}; // 2
    display(vec2);
    vector<string> vec3(vec2.begin(), vec2.end()); // 3
    display(vec3);
    vector<string> vec4(vec3); // 4
    display(vec4);
    cout << endl;

    // deque常用的4种构造方式
    deque<string> deq1(3, "a"); // 1
    display(deq1);
    deque<string> deq2{"beijing", "shanghai", "shenzhen", "nanjing"}; // 2
    display(deq2);
    deque<string> deq3(deq2.begin(), deq2.end()); // 3
    display(deq3);
    deque<string> deq4(deq3); // 4
    display(deq4);
    cout << endl;

    // list常用的4种构造方式
    list<string> list1(3, "a"); // 1
    display(list1);
    deque<string> list2{"beijing", "shanghai", "shenzhen", "nanjing"}; // 2
    display(list2);
    deque<string> list3(deq2.begin(), deq2.end()); // 3
    display(list3);
    deque<string> list4(deq3); // 4
    display(list4);
}

// assign，替换容器的内容
void test1()
{
    // vector3种替换方式
    vector<string> vec1{"1", "2"};
    vector<string> vec2{"3", "4"};
    vec1.assign(3, "a"); // 1
    display(vec1);
    vec1.assign(vec2.begin(), vec2.end()); // 2
    display(vec1);
    vec1.assign({"c++", "11"}); // 3
    display(vec1);
    cout << endl;

    // deque3种替换方式
    deque<string> deq1{"1", "2"};
    deque<string> deq2{"3", "4"};
    deq1.assign(3, "a"); // 1
    display(deq1);
    deq1.assign(vec2.begin(), vec2.end()); // 2
    display(deq1);
    deq1.assign({"c++", "11"}); // 3
    display(deq1);
    cout << endl;

    // list3种替换方式
    list<string> list1{"1", "2"};
    list<string> list2{"3", "4"};
    list1.assign(3, "a"); // 1
    display(list1);
    list1.assign(vec2.begin(), vec2.end()); // 2
    display(list1);
    list1.assign({"c++", "11"}); // 3
    display(list1);
    cout << endl;
}

// 元素访问
void test2()
{
    // vector4种常用访问方式
    vector<int> vec1{1, 2, 3, 4, 5, 6};
    vec1.at(1) = 88; // at函数返回位于指定位置 pos 的元素的引用，有边界检查。
    try {
        vec1.at(6) = 66;
    } catch (std::out_of_range const &exc) {
        std::cout << exc.what() << '\n';
    }
    vec1[5] = 55; // 索引访问
    vec1.front() = 11; // front函数返回首元素的引用。
    vec1.back() = 66; // back函数返回最后元素的引用。
    display(vec1);
    cout << endl;

    // deque4种常用访问方式
    deque<int> deq1{1, 2, 3, 4, 5, 6};
    deq1.at(1) = 88; // at函数返回位于指定位置 pos 的元素的引用，有边界检查。
    try {
        deq1.at(6) = 66;
    } catch (std::out_of_range const &exc) {
        std::cout << exc.what() << '\n';
    }
    deq1[5] = 55; // 索引访问
    deq1.front() = 11; // front函数返回首元素的引用。
    deq1.back() = 66; // back函数返回最后元素的引用。
    display(deq1);
    cout << endl;

    // list2种常用访问方式
    list<int> list1{1, 2, 3, 4, 5, 6};
    list1.front() = 77; // front函数返回首元素的引用。
    list1.back() = 99; // back函数返回最后元素的引用。
    display(list1);
    cout << endl;
}

// 迭代器
void test3()
{
    // 3种容器拥有同样的迭代器
    vector<int> vec1{1, 2, 3, 4, 5, 6};
    for (auto it = vec1.begin(); it != vec1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = vec1.rbegin(); it != vec1.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    deque<int> deq1{1, 2, 3, 4, 5, 6};
    for (auto it = deq1.begin(); it != deq1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = deq1.rbegin(); it != deq1.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    list<int> list1{1, 2, 3, 4, 5, 6};
    for (auto it = list1.begin(); it != list1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = list1.rbegin(); it != list1.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// 容量
void test4()
{
    // vector5种常用的容量函数
    vector<int> vec1{1, 2, 3, 4, 5, 6};
    if (!vec1.empty()) { // 检查容器是否为空
        cout << "size = " << vec1.size() << endl; // 返回容器中的元素数
        cout << "capacity = " << vec1.capacity() << endl; // 返回容器当前已为之分配空间的元素数
        vec1.reserve(10); // 若参数大于capacity，则增加vector的capacity，且所有迭代器失效；反之什么也不做；
        cout << "size = " << vec1.size() << endl;
        cout << "capacity = " << vec1.capacity() << endl;
        vec1.reserve(5);
        cout << "size = " << vec1.size() << endl;
        cout << "capacity = " << vec1.capacity() << endl;
        auto it = vec1.begin();
        cout << "before shrink_to_fit " << *it << endl;
        vec1.shrink_to_fit(); // 当capacity大于size时，使capacity与size值一样，且所有迭代器失效；反之什么也不做。
//        cout << "after shrink_to_fit " << *it << endl;
        cout << "size = " << vec1.size() << endl;
        cout << "capacity = " << vec1.capacity() << endl;
        cout << endl;
    }

    // deque3种常用的容量函数
    deque<int> deq1{1, 2, 3, 4, 5, 6};
    if(!deq1.empty()) { // 检查容器是否为空
        cout << "size = " << deq1.size() << endl; // 返回容器中的元素数
        deq1.clear();
        cout << "size = " << deq1.size() << endl;
        deq1.shrink_to_fit(); // 释放不使用的内存，前面clear清除容器中所有的元素，但分配的内存还在
    }

    // list2种常用的容量函数
    list<int> list1{1, 2, 3, 4, 5, 6};
    if(!list1.empty()) {
        cout << "size = " << list1.size() << endl;
    }
}

// 修改器
void test5()
{
    // vector
    vector<int> vec1{1, 2, 3, 4, 5, 6};
    auto it = vec1.begin();
    cout << "before clear " << *it << endl;
    vec1.clear(); // 擦除容器所有元素，此后size为0，capacity不变，迭代器失效，但分配的内存还在
//    *it = 999;
//    cout << "after clear " << *it << endl;
    cout << "size = " << vec1.size() << endl;
    cout << "capacity = " << vec1.capacity() << endl;

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
    it1 = svec.insert(svec.end(), {"dd", "ee", "ff"}); // 通过初始化列表插入给定位置前，返回被插入元素首元素的迭代器
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

    // deque，包含上面的函数
    deque<int> deq1{1, 2, 3};
    deq1.push_front(0);
    display(deq1);
    deq1.pop_front();
    display(deq1);
    deq1.emplace_front(0);
    display(deq1);
    cout << endl;

    // list，包含上面的函数，与deque一致

}

int main()
{
//    test0();
//    test1();
//    test2();
//    test3();
//    test4();
    test5();

    return 0;
}

