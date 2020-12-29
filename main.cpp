#include<iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        this->m_Age = age;
    }

    void showAge()
    {
        cout << "年龄为：" << this->m_Age << endl;
    }
    ~Person()
    {
        cout << "Person的析构调用" << endl;
    }

    int m_Age;
};

//智能指针
//用来托管自定义类型的对象，让对象进行自动的释放
class smartPointer
{
private:
    Person * person;
public:
    smartPointer(Person * person) {
        this->person = person;
    }

    //重载->让智能指针对象 像Person *p一样去使用
    Person * operator->() {
        return this->person;
    }

    //重载 *
    Person& operator*()
    {
        return *this->person;
    }

    ~smartPointer()
    {
        cout << "智能指针析构了" << endl;
        if (this->person != NULL)
        {
            delete this->person;
            this->person = NULL;
        }
    }
};

void test01()
{
    //Person p1(10); //自动析构

    //Person * p1 = new Person(10);
    //p1->showAge();
	//delete p1;

    smartPointer sp(new Person(10)); //sp开辟到了栈上，自动释放，调用析构
    sp->showAge(); // sp->->showAge(); 编译器优化了 写法
    (*sp).showAge();
}

int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;
}
