//
// Created by 张兴 on 2020-12-27.
//

#include <iostream>
using namespace std;

class MyString
{
public:
    MyString(const char * str)
    {
        //
    }

    // explicit关键字 ，防止隐式类型转换
    explicit MyString(int a)
    {
        mSize = a;
    }

    char* mStr;
    int mSize;
};

void test01()
{

    MyString str = "abc";
    MyString str2(10);
    //MyString str3 = 10;   //做什么用途？ str2字符串为 "10" 字符串的长度10
    //隐式类型转换  Mystring str3 = Mystring (10);
}

int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;
}
