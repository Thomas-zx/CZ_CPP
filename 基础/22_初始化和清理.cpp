//
// Created by 张兴 on 2020-12-27.
//

#include<iostream>
using namespace std;

class Person
{
public:
    //构造函数写法
    //与类名相同，没有返回值，不写void，可以发生重载（可以有参数）
    //构造函数由编译器自动调用，而不是手动，而且只会调用一次
    Person()
    {
        cout << "构造函数调用" << endl;
    }

    Person(int a)
    {
        cout << "构造函数调用(int a)" << endl;
    }

    //析构函数写法
    // 与类名相同 类名前面加一个符号 “~” ,也没有返回值 ，不写void， 不可以有参数（不能发生重载）
    //自动调用，只会调用一次
    ~Person()
    {
        cout << "析构函数调用" << endl;
    }
};

void test01()
{
    Person p1(1); //默认调用了构造和析构，是系统提供的两个空实现的函数
    cout << "函数完成开始调用析构函数调用" << endl;
}

int main()
{
    test01();
    cout << "test01" << endl;

    system("pause");
    return EXIT_SUCCESS;
}
