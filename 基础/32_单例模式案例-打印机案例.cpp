//
// Created by 张兴 on 2020-12-27.
//

#include <iostream>
#include <string>
using namespace std;

class Printer
{
private:
    static Printer *singlePrinter;
    int m_Count;

    Printer() {  m_Count = 0; }
    Printer(const Printer& p);

public:
    static Printer* getInstance()
    {
        return singlePrinter;
    }

    void printText(string text)
    {
        cout << text <<endl;
        m_Count++;
        cout << "打印机使用的次数为：" << m_Count << endl;
    }
};

Printer* Printer::singlePrinter = new Printer;

void test01()
{
    //拿到打印机
    Printer * printer =  Printer::getInstance();

    printer->printText("离职报告");
    printer->printText("入职报告");
    printer->printText("加薪申请");
    printer->printText("升级申请");
    printer->printText("退休申请");
}

int main()
{
    test01();

    system("pause");
    return EXIT_SUCCESS;
}
