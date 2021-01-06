//
// Created by 张兴 on 2020/12/26.
//

#include<iostream>
using namespace std;
//07 C语言中的const默认是外部链接
//08 C++语言中const默认是内部链接
int main()
{
    //C:告诉编译器在a在外部
    extern const int a;
    cout << a << endl;

    system("pause");
    return EXIT_SUCCESS;
}