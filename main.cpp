#include <iostream>

using namespace std;
class Person
{
    friend ostream& operator<<(ostream &cout, Person &p1);
public:
    Person() {m_A = 0; m_B = 0;};
    Person(int a, int b) : m_A(a), m_B(b)
    {}

    /*void operator<<()重载左移运算符不可以写到成员函数中
    */
public:
    int m_A;
    int m_B;
};

ostream& operator<<(ostream &cout, Person &p1)  //第一个参数 cout，第二个参数 p1
{
    cout << "m_A = " << p1.m_A << " m_B = " << p1.m_B << " ";

    return cout;
}

void test01()
{
    Person p1(10, 10);

    cout << p1 << "hello,world" <<endl;
}

int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;
}