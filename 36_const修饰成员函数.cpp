//
// Created by 张兴 on 2020-12-27.
//

#include<iostream>
using namespace std;

//1.const修饰普通类型的变量
//const int a = 7;

//2.const 修饰指针变量
//A: const 修饰指针指向的内容，则内容为不可变量
//const int *p = 8;  //左定值,指针指向的内容 8 不可改变
//B: const 修饰指针，则指针为不可变量。
//int* const p = &a;  //右定向,对于 const 指针 p 其指向的内存地址不能够被改变，但其内容可以改变
//C: const 修饰指针和指针指向的内容，则指针和指针指向的内容都为不可变量。
//const int * const  p = &a;

//3.const参数传递
//A：值传递的 const 修饰传递，一般这种情况不需要 const 修饰，因为函数会自动产生临时变量复制实参值。
//void Cpf(const int a)
//B：当 const 参数为指针时，可以防止指针被意外篡改。
//void Cpf(int *const a)
//C：自定义类型的参数传递，需要临时对象复制参数，对于临时对象的构造，需要调用构造函数，比较浪费时间，因此我们采取 const 外加引用传递的方法。
//void Cmf(const Test& _tt)

//4.const修饰返回值分三种情况
//A：const 修饰内置类型的返回值，修饰与不修饰返回值作用一样。
//const int Cmf()
//B: const 修饰自定义类型的作为返回值，此时返回的值不能作为左值使用，既不能被赋值，也不能被修改。
//C: const 修饰返回的指针或者引用，是否返回一个指向 const 的指针，取决于我们想让用户干什么。

class Person
{
public :
    Person()
    {
        //构造中修改属性
        //this 永远执行本体
        this->m_A = 0;
        this->m_B = 0;
    }

    void showInfo() const //常函数 不允许修改指针指向的值, 相当于const Type * const this
    {
        //this->m_A = 1000;
        this->m_B = 1000;
        // const Person * const this
        cout << "m_A = " << this->m_A << endl;
        cout << "m_B = " << this->m_B << endl;
    }

    void show2() const
    {
        //m_A = 100;
    }

    int m_A;
    mutable int m_B; //就算是常函数 我还是执意要修改
};

void test01()
{
    Person p1;
    p1.showInfo();

    //常对象 不允许修改属性
    const Person p2;
    cout << p2.m_A << endl;
    p2.show2();
    //常对象 不可以调用普通成员函数
    //常对象 可以调用常函数
}

int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;
}
