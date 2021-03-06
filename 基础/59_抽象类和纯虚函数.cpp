//
// Created by 张兴 on 2020-12-30.
//
//
// Created by 张兴 on 2020-12-30.
//
#include <iostream>
#include <string>
using namespace std;

//class Calculator
//{
//public:
//
//    void setv1(int v) {
//       this->val1 = v;
//    }
//    void setv2(int v) {
//        this->val2 = v;
//    }
//
//    int getResult(string oper)
//    {
//        if (oper == "+") {
//            return val1 + val2;
//        }
//        else if (oper == "-") {
//            return val1 - val2;
//        }
//    }
//
//    int val1;
//    int val2;
//};

//void test01()
//{
//    int val;
//
//    Calculator cal;
//    cal.setv1(10);
//    cal.setv2(20);
//    val = cal.getResult("+");
//    cout << val << endl;
//}

//如果父类中有了纯虚函数，子类继承父类，子类必须实现纯虚函数
//如果父类中有了纯虚函数，这个父类就无法实例化对象了
//这个类有了纯虚函数，通常又被称为抽象类

//利用多态实现计算器
class abstractCalculator
{
public:
    //virtual int getResult() { return 0;}

    //纯虚函数
    virtual int getResult() = 0;

    void setv1(int v) {
        this->val1 = v;
    }
    void setv2(int v) {
        this->val2 = v;
    }

    int getv1() {
        return this->val1;
    }
    int getv2() {
        return this->val2;
    }
private:
    int val1;
    int val2;
};

class PlusCalculator : public abstractCalculator
{
public:
    virtual int getResult() {
        return getv1() + getv2();
    }
};

class SubCalculator : public abstractCalculator
{
public:
    virtual int getResult() {
        return getv1() - getv2();
    }
};

//扩展
class DivCalculator : public abstractCalculator
{
public:
    virtual int getResult() {
        return getv1() / getv2();
    }
};

void test02()
{
    abstractCalculator *abc;

    //如果父类中有了纯虚函数，这个父类就无法实例化对象了
    //abstractCalculator abc1;
    //abstractCalculator *abc2 = new abstractCalculator;

    //加法计算器
    abc = new PlusCalculator;
    abc->setv1(15);
    abc->setv2(5);
    cout << "计算器:" << abc->getResult() << endl;

    delete abc;

    abc = new SubCalculator;
    abc->setv1(15);
    abc->setv2(5);
    cout << "计算器:" << abc->getResult() << endl;

    delete abc;

    abc = new DivCalculator;
    abc->setv1(15);
    abc->setv2(5);
    cout << "计算器:" << abc->getResult() << endl;
}

int main()
{
    //test01();
    test02();

    system("pause");
    return EXIT_SUCCESS;
}
