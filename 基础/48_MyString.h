//
// Created by 张兴 on 2020-12-29.
//

#pragma once
#include <iostream>
using namespace std;

class MyString
{
    friend ostream& operator<< (ostream& cout, MyString &str);
    friend istream& operator>> (istream& cin, MyString & str);
private:
    char * pString;
    int m_Size;
public:
    MyString(const char * str);
    MyString(const MyString & str);

    ~MyString();

    //重载=运算符
    MyString& operator= (const char * str);
    MyString& operator= (const MyString & str);

    //重载[]运算符
    char& operator[](int index);

    //重载 +运算符
    MyString operator+ (const char * str);
    MyString operator+ (const MyString& str);

    //重载 == 运算符
    bool operator== (const char * str);
    bool operator== (const MyString & str);
};
