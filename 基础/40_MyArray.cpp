//
// Created by 张兴 on 2020-12-28.
//

#include "40_MyArray.h"

//默认构造
MyArray::MyArray()
{
    this->m_Capacity = 100;
    this->m_size = 0;
    this->pAddr = new int[this->m_Capacity];
}

//有参构造  参数 数组容量
MyArray::MyArray(int capacity)
{
    this->m_Capacity = capacity;
    this->m_size = 0;
    this->pAddr = new int[this->m_Capacity];
}

//拷贝构造
MyArray::MyArray(const MyArray &array)
{
    cout << "拷贝构造调用" << endl;
    this->pAddr = new int[array.m_Capacity];
    this->m_size = array.m_size;
    this->m_Capacity = array.m_Capacity;

    for (int i = 0; i < array.m_size; i++) {
        this->pAddr[i] = array.pAddr[i];
    }
}

//析构
MyArray::~MyArray()
{
    if (this->pAddr != NULL) {
        delete[] this->pAddr;
        this->pAddr = NULL;
    }
}

void MyArray::pushBack(int val)
{
    this->pAddr[this->m_size] = val;
    this->m_size++;
}

int MyArray::getData(int index)
{
    return this->pAddr[index];
}

void MyArray::setData(int index, int val)
{
    this->pAddr[index] = val;
}

int MyArray::getSize()
{
    return this->m_size;
}

int MyArray::getCapacity()
{
    return this->m_Capacity;
}

int& MyArray::operator[](int index)
{
    return this->pAddr[index];
}