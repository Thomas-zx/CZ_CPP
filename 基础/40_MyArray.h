//
// Created by 张兴 on 2020-12-28.
//

#pragma once

#include <iostream>
using namespace std;

class MyArray
{
public:
    MyArray();  //默认构造  默认100容量
    MyArray(int capacity);
    MyArray(const MyArray& array);

    ~MyArray();

    void pushBack(int val); //尾插法

    int getData(int index);  //根据索引获取值

    void setData(int index, int val);   //根据索引设置值

    int getSize(); //获取数组大小

    int getCapacity();  //获取数组容量

    int&operator[](int index);  //[]运算符重载

private:
    int * pAddr;//指向真正存储数据的指针
    int m_size;//数组大小
    int m_Capacity;//数组容量
};