#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <list>

using namespace std;

//C++迭代器失效
//一、序列式容器(数组型数据结构)
//对于序列式容器(如vector,deque)，序列式容器就是数组式容器，
// 删除当前的iterator会使后面所有元素的iterator都失效

void vectorTest()
{
    vector<int> container;
    for (int i = 0; i < 10; i++)
    {
        container.push_back(i);
    }

    vector<int>::iterator iter;
    for (iter = container.begin(); iter != container.end(); iter++)
    {
        cout<< "current:" <<*iter << endl;
        if (*iter > 3) {
            cout<< "del:" <<*iter << endl;
            iter = container.erase(iter);  //erase的返回值是删除元素下一个元素的迭代器
            iter--;
        }
    }

    for (iter = container.begin(); iter != container.end(); iter++)
    {
        cout<<*iter<<endl;
    }
}

//二、关联式容器(树形数据结构)
//对于关联容器(如map, set, multimap,multiset)，
// 删除当前的iterator，仅仅会使当前的iterator失效，
// 只要在erase时，递增当前iterator即可

//测试错误的Map删除元素
void mapTest()
{
    map<int, string> dataMap;

    for (int i = 0; i < 10; i++)
    {
        string strValue = "Hello, World";
        stringstream ss;
        ss<<i;
        string tmpStrCount;
        ss>>tmpStrCount;
        strValue += tmpStrCount;
        dataMap.insert(make_pair(i, strValue));
    }

    cout<<"MAP元素内容为："<<endl;
    map<int, string>::iterator iter;
    for (iter = dataMap.begin(); iter != dataMap.end(); iter++)
    {
        int nKey = iter->first;
        string strValue = iter->second;
        cout<<strValue<<endl;
    }

    cout<<"内容开始删除："<<endl;
    //删除操作引发迭代器失效
    for (iter = dataMap.begin(); iter != dataMap.end();iter++)
    {
        int nKey = iter->first;
        string strValue = iter->second;

        //if (nKey % 2 == 0)
        //{
        //    dataMap.erase(iter);    //错误
        //}

        if (nKey % 2 == 0)
        {
            dataMap.erase(iter++);
            auto a = iter;
        } else {
            iter++;
        }
    }

    cout<<"MAP元素内容为："<<endl;
    for (auto iter = dataMap.begin(); iter != dataMap.end(); iter++)
    {
        int nKey = iter->first;
        string strValue = iter->second;
        cout<<strValue<<endl;
    }
}

//三、链表式容器(链表型数据结构)
//对于链表式容器(如list)，
// 删除当前的iterator，仅仅会使当前的iterator失效，
// 这是因为list之类的容器，使用了链表来实现，插入、删除一个结点不会对其他结点造成影响。

void printList(list<int>&L)
{
    for (list<int>::iterator it = L.begin(); it != L.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void listTest()
{
    list<int> myList;
    for (int i = 0; i < 10; i++) {
        myList.push_back(i);
    }
    printList(myList);

    for (auto iter = myList.begin(); iter != myList.end(); iter++)
    {
        if (*iter > 3)
            myList.erase(iter);
    }

    //方式一:递增当前iterator
    //for (auto iter = myList.begin(); iter != myList.end();)
    //{
    //    if (*iter > 3)
    //        myList.erase(iter++);
    //    else
    //        ++iter;
    //}

    //方式二:通过erase获得下一个有效的iterator
    //for (auto iter = myList.begin(); iter != myList.end();)
    //{
    //    if (*iter > 3)
    //        iter = myList.erase(iter);  //erase删除元素，返回下一个迭代器
    //    else
    //        ++iter;
    //}

    printList(myList);
}

int main(int argc, char *argv[])
{
    //vectorTest();
    //mapTest();
    listTest();

    return 0;
}