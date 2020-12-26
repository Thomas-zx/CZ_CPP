//
// Created by 张兴 on 2020/12/26.
//

#include<iostream>
using namespace std;

int atk = 200;
void test01(void)
{
    int atk = 100;

    cout << "攻击力为 ： " << atk << endl;
    //双冒号 作用域运算符  ::全局作用域
    cout << "全局攻击力为 ： " << ::atk << endl;
}

int main(){

    test01();

    system("pause");
    return EXIT_SUCCESS;
}