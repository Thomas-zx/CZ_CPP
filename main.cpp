#include <iostream>

using namespace std;

class Test
{
public:
    Test(int i) : data(i) {}

private:
    int data;
};

class Test1
{
public:
    //【1】显式缺省函数（=default）
    Test1() = default;  // 显式指定缺省函数
    Test1(int i) : data(i) {}
    //【2】显式删除函数（=delete）
    //需要禁止拷贝构造函数的使用
    Test1(const Test& t) = delete; // 显式删除拷贝构造函数


private:
    int data;
};

//【3】其他应用
class Example
{
public:
    Example() = default;
    Example(const Example&);
    Example(int i) {}
    Example(char c) = delete;

private:
    int data;
};

Example::Example(const Example& ex) = default;

void func(int i) {}
void func(char c) = delete;

int main()
{
    //POD全称Plain Old Data。通俗的讲，一个类或结构体通过二进制拷贝后还能保持其数据不变，那么它就是一个POD类型。
    std::cout << std::is_pod<Test>::value << std::endl;  // 0
    std::cout << std::is_pod<Test1>::value << std::endl;

    Test1 objT1;
    //Test1 objT2(objT1); // 无法通过编译

    Example ex(1);
    //Example ex1('a');  // 无法通过编译

    func(1);
    //func('a');  // 无法通过编译
}