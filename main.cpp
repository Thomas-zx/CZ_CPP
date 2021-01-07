#include <iostream>
#include <string>
#include <vector>
using namespace std;

//auto可以在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型

void test01()
{
    int a = 10;
    auto au_a = a;  //自动类型推断，au_a为int类型
    cout << typeid(au_a).name() << endl;
}

//1.用于代替冗长复杂、变量使用范围专一的变量声明
void test02()
{
    vector<string> vs;
    //for (vector<string>::iterator it = vs.begin(); it != vs.end(); it++)
    for (auto it = vs.begin(); it != vs.end(); it++) {
        //...
    }
}

//2.在定义模板函数时，用于声明依赖模板参数的变量类型
template <typename _Tx, typename _Ty>
void Multiply(_Tx x, _Ty y)
{
    auto v = x * y;
    std::cout << v;
}

//3.模板函数依赖于模板参数的返回值
template <typename _Tx, typename _Ty>
auto multiply(_Tx x, _Ty y)->decltype(x * y)
{
    return x * y;
}
//decltype
//希望从表达式的类型推断出要定义的变量类型
//但是不想用该表达式的值初始化变量（初始化可以用auto）


int main(int argc, char *argv[])
{
    test01();
    //test02();

    return 0;
}