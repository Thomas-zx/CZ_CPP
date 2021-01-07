#include <iostream>

using namespace std;

//nullptr关键字来代指空指针
//nullptr为了解决NULL表示空指针在C++中具有二义性的问题
//C语言中
// NULL通常被定义为：#define NULL ((void *)0)
//C++语言中
// NULL,void*是不能隐式转换成其他类型的指针的
//#ifdef __cplusplus
//#define NULL 0
//#else
//#define NULL ((void *)0)
//#endif

void func(void* i)
{
    cout << "func1" << endl;
}

void func(int i)
{
    cout << "func2" << endl;
}

int main(int argc,char* argv[])
{
    //func(NULL);
    func(nullptr);
    getchar();

    return 0;
}
const class nullptr_t
{
public:
    template <class T>
    inline operator T*() const {return 0;}

    template <class C, class T>
    inline operator T C::*() const {return 0;}

private:
    void operator&() const;
} _nullptr_ = {};