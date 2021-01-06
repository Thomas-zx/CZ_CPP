#include <iostream>
#include <string>
//容器 vector
#include <vector>
//使用系统算法的头文件
#include <algorithm>

using namespace std;

void test01()
{
    int array[5] = {1, 3, 4, 5, 7};
    int *p = array;  //指针指向数组首地址 &array[0]

    for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
        //cout << array[i] << endl;
        cout << *(p++) << endl;
    }
}

void myPrint(int v)
{
    cout << v << endl;
}

void test02()
{
    //声明一个容器 这个容器中存放int类型数据 对象名称array
    vector<int> array;

    //向容器中加入数据
    array.push_back(10);
    array.push_back(20);
    array.push_back(30);
    array.push_back(40);

    //遍历容器中的数据
    //利用迭代器
    vector<int>::iterator itBegin = array.begin();  // itBegin指向的是v容器中的起始位置
    vector<int>::iterator itEnd = array.end();  //itEnd指向v容器中最后一个位置的下一个地址

    //while (itBegin != itEnd) {
    //    cout << *itBegin << endl;
    //    itBegin++;
    //}

    //第二种遍历方式
    //for (vector<int>::iterator it = array.begin(); it != array.end(); it++) {
    //    cout << *it << endl;
    //}

    //第三种方式 利用算法
    for_each(array.begin(), array.end(), myPrint);
}

class Person
{
public:
    Person(string name, int age)
    {
        this->mName = name;
        this->mAge = age;
    }

    string mName;
    int mAge;
};

void test03()
{
    vector<Person> v;
    Person p1("大头儿子", 10);
    Person p2("小头爸爸", 32);
    Person p3("隔壁王叔叔", 30);
    Person p4("围裙妈妈", 28);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //遍历
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "姓名: " << (*it).mName << " 年龄：" << it->mAge << endl;
    }
}

//存放自定义数据类型的指针
void test04()
{
    vector<Person *> v;

    Person p1("大头儿子", 10);
    Person p2("小头爸爸", 32);
    Person p3("隔壁王叔叔", 30);
    Person p4("围裙妈妈", 28);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    for(vector<Person *>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "姓名：： " << (*it)->mName << " 年龄： " << (*it)->mAge << endl;
    }
}

//容器嵌套容器
void test05()
{
    vector<vector<int>> v;

    vector<int>v1;
    vector<int>v2;
    vector<int>v3;

    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 10);
        v3.push_back(i + 100);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
            cout << *vit << " ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    //test01();
    //test02();
    //test03();
    //test04();
    test05();

    system("pause");
    return EXIT_SUCCESS;
}