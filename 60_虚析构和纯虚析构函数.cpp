//
// Created by 张兴 on 2020-12-30.
//

#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }

    Animal()
    {
        cout << "Animal的构造调用" << endl;
    }

    //普通析构 是不会调用子类的析构的，所以可能会导致释放不干净
    //利用虚析构来解决这个问题
    //virtual ~Animal()
    //{
    //    cout << "Animal的析构调用" << endl;
    //}

    //纯虚析构 写法如下
    //纯虚析构 ，需要声明 还需要实现 类内声明，类外实现
    virtual ~Animal() = 0;
    //如果函数中出现了 纯虚析构函数，那么这个类也算抽象类
    //抽象类 不可实例化对象
};

Animal::~Animal()
{
    //纯虚析构函数实现
    cout << "Animal的纯虚析构调用" << endl;
}

// 如果出现纯虚析构，类也算抽象类，不能实例化对象
//void func()
//{
//	Animal an;
//	Animal * animal = new Animal;
//}

class Cat : public Animal
{
public:
    Cat(const char * name)
    {
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name, name);
    }

    virtual void speak()
    {
        cout << "小猫在说话" << endl;
    }

    ~Cat()
    {
        cout << "Cat的析构调用" << endl;
        if (this->m_Name != NULL)
        {
            delete[] this->m_Name;
            this->m_Name = NULL;
        }
    }

    char * m_Name;
};

void test01()
{
    Animal * animal = new Cat("TOM");
    animal->speak();

    delete animal;
}
//基类 转 派生类 不安全 向下类型转换
//派生类 转 基类 安全 向上类型转换
//如果发生了多态，总是安全的
int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;
}
