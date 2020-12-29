#include <iostream>

using namespace std;

class MyInteger
{
    friend ostream& operator<<(ostream& cout, MyInteger & myInt);
private:
    int m_Num;

public:
    MyInteger() { m_Num = 0; }

    //前置++重载
    MyInteger&operator++() {
        this->m_Num++;
        return *this;
    }

    //后置++ 重载
    MyInteger operator++(int) {
        //先保存目前数据
        MyInteger tmp = *this;
        m_Num++;
        return tmp;
    }
};

ostream& operator<<( ostream& cout ,MyInteger & myInt)
{
    cout << myInt.m_Num;
    return cout;
}

void test01()
{
    MyInteger myInt;

    // 前置++
    cout << ++(++myInt) << endl;
    cout << myInt << endl;

    myInt++; // 后置++
    cout << myInt << endl;
}

int main()
{
    test01();

    /*int a = 10;
    cout << ++(++a) << endl;
    cout << a << endl;*/

    system("pause");
    return EXIT_SUCCESS;
}