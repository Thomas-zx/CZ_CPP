//
// Created by 张兴 on 2020-12-31.
//
#include <iostream>
using namespace std;

//交换int类型两个数字
void mySwapInt(int & a, int & b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

//交换double数据
void mySwapDouble(double &a, double &b)
{
    double tmp = a;
    a = b;
    b = tmp;
}

//类型，逻辑又非常相似
//类型参数化  泛型编程 -- 模板技术
template <class T> // 告诉编译器 下面如果出现T不要报错，T是一个通用的类型
void mySwap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

// template<typename T>  等价于 template<class T>
template <typename T>
void mySwap2(){}

void test01()
{
    int a = 10;
    int b = 20;
    char c1 = 'c';

    mySwapInt(a, b);
    cout << "1.a = " << a  << ",b = " << b << endl;

    //1.自动类型推导,必须有参数类型才可以推导
    //mySwap(a, c1); 推导不出来T，所以不能运行
    mySwap(a, b);
    cout << "2.a = " << a  << ",b = " << b << endl;

    //2.显示指定类型
    mySwap<int>(a, b);
    cout << "3.a = " << a  << ",b = " << b << endl;

    //mySwap2();  //模板必须要指定出T才可以使用
    mySwap2<double>();

    double c = 3.14;
    double d = 1.1;
    mySwapDouble(c, d);
    cout << "4.c = " << c  << ",d = " << d << endl;

    mySwap(c, d);
    cout << "5.c = " << c  << ",d = " << d << endl;
}

int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;
}
