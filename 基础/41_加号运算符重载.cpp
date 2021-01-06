//
// Created by 张兴 on 2020-12-29.
//
#include <iostream>

using namespace std;
class Person
{
public:
    Person() {m_A = 0; m_B = 0;};
    Person(int a, int b) : m_A(a), m_B(b)
    {}

    //+号运算符重载 成员函数 二元
    /*Person operator+ (Person &p)
    {
        Person tmp;
        tmp.m_A = this->m_A + p.m_A;
        tmp.m_B = this->m_B + p.m_B;
        return tmp;
    }*/
public:
    int m_A;
    int m_B;
};

//利用全局函数 进行+号运算符的重载
Person operator+(Person &p1, Person &p2)
{
    Person tmp;

    tmp.m_A = p1.m_A + p2.m_A;
    tmp.m_B = p1.m_B + p2.m_B;

    return tmp;
}

Person operator+(Person &p1, int a) //二元
{
    Person tmp;

    tmp.m_A = p1.m_A + a;
    tmp.m_B = p1.m_B + a;

    return tmp;
}

void test01()
{
    Person p1(10, 10);
    Person p2(10, 10);

    Person p3 = p1 + p2;
    Person p4 = p1 + 10;
    Person p5;
    //p5 = p5.operator+(p2);

    cout << "p3 的 m_A: " << p3.m_A << "  m_B: " << p3.m_B << endl;
    cout << "p4 的 m_A: " << p4.m_A << "  m_B: " << p4.m_B << endl;
    //cout << "p5 的 m_A: " << p5.m_A << "  m_B: " << p5.m_B << endl;
}

int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;
}
