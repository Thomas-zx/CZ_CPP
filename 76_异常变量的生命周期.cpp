//
// Created by 张兴 on 2021-01-06.
//

#include <iostream>
using namespace std;

class MyException
{
public:
    MyException()
    {
        cout << "MyException的默认构造" << endl;
    }

    MyException(const MyException & e)
    {
        cout << "MyException的拷贝构造" << endl;
    }

    ~MyException()
    {
        cout << "MyException的析构调用" << endl;
    }

    void printError()
    {
        this->m_A = 100;
        cout << "error："  << m_A<< endl;
    }

    int m_A;
};

void doWork()
{
    //throw new MyException();  //2.需要手动释放
    MyException e;

    throw &e;
}

void test01()
{
    try
    {
        doWork();
    }
    catch (MyException *e) //1.MyException e，会多开销一份数据
    {
        cout << "捕获异常" << endl;
        //delete e; //靠自觉 释放对象

        //e->printError();
        //e->printError();
        //e->printError(); //指向非法内存空间，不应该这么做
    }
}

int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;
}
