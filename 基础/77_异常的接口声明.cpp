//
// Created by 张兴 on 2021-01-06.
//

#include <iostream>
using namespace std;

//异常的接口声明
void func() throw(int, char, double) //throw(int)只能抛出int类型异常  throw()不抛出任何类型异常
{
    //throw 1;
    //throw 'e';
    throw 3.14;
    //throw "err";  //定义中没有const char *, throw后catch不到
}

int main(int argc, char *argv[])
{
    try {
        func();
    }catch (int) {
        cout << "int类型异常捕获" << endl;
    }catch (const char *str) {
        cout << "char *类型异常捕获" << endl;
    }catch (...) {
        cout << "其他类型异常捕获" << endl;
    }

    system("pause");
    return EXIT_SUCCESS;
}
