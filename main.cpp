#include <iostream>
using namespace std;

void func() throw(int, char, double)
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