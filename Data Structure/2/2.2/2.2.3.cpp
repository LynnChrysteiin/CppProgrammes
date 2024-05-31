/*
目的：使用C++模板设计单链表的抽象数据类型（ADT）。
并在此基础上，使用单链表ADT的基本操作，设计并实现单链表的简单算法设计。
内容：
（1）请使用模板设计单链表的抽象数据类型。
    （由于该环境目前仅支持单文件的编译，故将所有内容都集中在一个源文件内。
    在实际的设计中，推荐将抽象类及对应的派生类分别放在单独的头文件中。参考网盘中的ADT原型文件。）
（2）ADT的简单应用：使用该ADT设计并实现单链表应用场合的一些简单算法设计。

应用1：假设有一个带头结点的单链表A，现要求设计一个算法，实现单链表的就地逆置，
即利用原表的存储空间实现表中前m 个元素和后n 个元素的互换。

参考函数原型：
template<class ElemType>
void Exchange_L( LinkList<ElemType> &L, int m );
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <class Iter>
struct ListNode
{
private:
    Iter data;
    struct ListNode *next;

public:
    ListNode<Iter> *getNext() { return next; }
    void setNext(ListNode<Iter> *next) { this->next = next; }
    Iter getData() { return data; }
    void setData(Iter data) { this->data = data; }
};

template <class Iter>
using LinkList = ListNode<Iter> *;

template <class Iter>
LinkList<Iter> createByTail()
{
    LinkList<Iter> L = new ListNode<Iter>;
    L->setNext(NULL);
    LinkList<Iter> p = L;
    string line;
    getline(cin, line);
    stringstream ss(line);
    Iter temp;
    while (ss >> temp)
    {
        LinkList<Iter> q = new ListNode<Iter>;
        q->setData(temp);
        q->setNext(NULL);
        p->setNext(q);
        p = q;
    }
    return L;
}

template <class Iter>
void Exchange_L(LinkList<Iter> &L, int m)
{
    LinkList<Iter> p = L->getNext();
    for (int i = 0; i < m - 1; ++i)
    {
        if (p == NULL)
            return;
        p = p->getNext();
    }
    LinkList<Iter> q = p->getNext();
    if (q == NULL)
        return;
    p->setNext(NULL);
    p = L->getNext();
    L->setNext(q);
    while (q->getNext() != NULL)
        q = q->getNext();
    q->setNext(p);
}

template <class Iter>
void doAll()
{
    LinkList<Iter> A = createByTail<Iter>();
    int m;
    cin >> m;

    LinkList<Iter> p = A->getNext();
    cout << p->getData();
    p = p->getNext();
    while (p != NULL)
    {
        cout << "->" << p->getData();
        p = p->getNext();
    }
    cout << endl
         << endl;

    Exchange_L(A, m);
    p = A->getNext();
    cout << p->getData();
    p = p->getNext();
    while (p != NULL)
    {
        cout << "->" << p->getData();
        p = p->getNext();
    }
}

int main()
{
    int type;
    cin >> type;
    getchar();
    if (type == 0)
        doAll<int>();
    else if (type == 1)
        doAll<double>();
    else if (type == 2)
        doAll<char>();
    else if (type == 3)
        doAll<string>();
    else
        cout << "err";
    return 0;
}