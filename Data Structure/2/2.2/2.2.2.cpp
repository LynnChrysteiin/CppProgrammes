/*
目的：使用C++模板设计单链表的抽象数据类型（ADT）。
并在此基础上，使用单链表ADT的基本操作，设计并实现单链表的简单算法设计。

内容：
（1）请使用模板设计单链表的抽象数据类型。
    （由于该环境目前仅支持单文件的编译，故将所有内容都集中在一个源文件内。
    在实际的设计中，推荐将抽象类及对应的派生类分别放在单独的头文件中。参考网盘中的ADT原型文件。）
（2）ADT的简单应用：使用该ADT设计并实现单链表应用场合的一些简单算法设计。

应用5：试设计一个算法，删除有序单链表A中的冗余元素，
即使得操作之后的单链表中只保留操作之前表中所有值都不相同的元素，并保持其有序性。
要求利用原表中的结点，并释放A表中冗余的结点空间。

参考函数原型：
template<class ElemType>
void Purge_Lk_OL( LinkList<ElemType> &A ); //测试数据限定为整数。实际应用时，不受其限制
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
void Purge_Lk_OL(LinkList<Iter> &A)
{
    LinkList<Iter> p = A->getNext();
    while (p != NULL)
    {
        LinkList<Iter> q = p->getNext();
        if (q != NULL && p->getData() == q->getData())
        {
            p->setNext(q->getNext());
            delete q;
        }
        else
            p = q;
    }
}

template <class Iter>
void doAll()
{
    LinkList<Iter> A = createByTail<Iter>();

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
    Purge_Lk_OL(A);
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