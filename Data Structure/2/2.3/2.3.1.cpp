/*
目的：
使用C++模板设计循环链表的抽象数据类型（ADT）。
并在此基础上，使用循环链表ADT的基本操作，设计并实现单链表的简单算法设计。

内容：
（1）请使用模板设计循环链表的抽象数据类型。
    （由于该环境目前仅支持单文件的编译，故将所有内容都集中在一个源文件内。
    在实际的设计中，推荐将抽象类及对应的派生类分别放在单独的头文件中。
    参考网盘中的单链表ADT原型文件，自行设计循环链表的ADT。）

（2）ADT的简单应用：使用该ADT设计并实现循环链表应用场合的一些简单算法设计。
    应用2：编号为1,2,...,n的n个人按顺时针方向围坐一圈，每人持有一个密码（正整数）。
    现在给定一个随机数m>0，从编号为1的人开始，按顺时针方向1开始顺序报数，报到m时停止。报m的人出圈，
    同时留下他的密码作为新的m值，从他在顺时针方向上的下一个人开始，重新从1开始报数，
    如此下去，直至所有的人全部出列为止。
    请在使用循环链表ADT的基础上，设计一个算法求出圈的顺序（以编号表示）。限定人数至少为1.

参考函数原型：
template<class ElemType>
void Joseph(CirLinkList<ElemType> &A, int m);

约瑟夫环专用结点类型
struct node{
    int number;
    int code;
};
*/

#include <iostream>
using namespace std;

struct node
{
    int number;
    int code;
};

template <class Iter>
struct CirLinkListNode
{
private:
    Iter Data;
    CirLinkListNode<Iter> *next;

public:
    Iter getData() { return Data; }
    CirLinkListNode *getNext() { return next; }
    void setData(Iter data) { Data = data; }
    void setNext(CirLinkListNode<Iter> *n) { next = n; }
    CirLinkListNode(Iter data, CirLinkListNode<Iter> *n) : Data(data), next(n) {}
    CirLinkListNode() : next(NULL) {}
};

template <class Iter>
using CirLinkList = CirLinkListNode<Iter> *;

template <class Iter>
CirLinkList<Iter> initCirLinkList() { return new CirLinkListNode<Iter>; }

template <class Iter>
CirLinkList<Iter> addByTail(CirLinkList<Iter> &A, Iter data)
{
    CirLinkListNode<Iter> *newNode = new CirLinkListNode<Iter>(data, NULL);
    if (A->getNext() == NULL)
    {
        A->setNext(newNode);
        newNode->setNext(newNode);
    }
    else
    {
        CirLinkListNode<Iter> *p = A->getNext();
        while (p->getNext() != A->getNext())
            p = p->getNext();
        p->setNext(newNode);
        newNode->setNext(A->getNext());
    }
    return A;
}

template <class Iter>
void popNode(CirLinkList<Iter> &A, CirLinkListNode<Iter> *p)
{
    if (p->getNext() == p)
    {
        delete p;
        A->setNext(NULL);
        return;
    }
    CirLinkListNode<Iter> *tempNode = p->getNext();
    p->setNext(tempNode->getNext());
    delete tempNode;
}

template <class Iter>
void Joseph(CirLinkList<Iter> &A, int m)
{
    CirLinkListNode<Iter> *p = A;
    while (p->getNext() != p)
    {
        for (int i = 1; i < m; i++)
            p = p->getNext();
        if (p->getNext()->getNext() == p->getNext())
        {
            cout << p->getNext()->getData().number << endl;
            return;
        }
        cout << p->getNext()->getData().number << "->";
        m = p->getNext()->getData().code;
        popNode(A, p);
    }
    cout << p->getData().number << endl;
}

int main()
{
    CirLinkList<node> A = initCirLinkList<node>();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        node temp;
        temp.number = i;
        cin >> temp.code;
        A = addByTail(A, temp);
    }
    CirLinkListNode<node> *p = A->getNext();
    cout << "(" << p->getData().number << "," << p->getData().code << ")";
    for (p = p->getNext(); p != A->getNext(); p = p->getNext())
        cout << "->(" << p->getData().number << "," << p->getData().code << ")";

    cout << endl
         << endl;
    int m;
    cin >> m;
    Joseph(A, m);
    return 0;
}