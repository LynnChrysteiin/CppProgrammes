/*
假设2个任意长度的整数x、y分别用链表A和B存储，现要求设计一个算法，实现x+y。计算结果存储在链表C中。

说明：
链表A、B、C可以是单向链表或双向链表，但由于A和B输出时需要从头至尾遍历，而做加法时需要从尾至头遍历，因此推荐使用双向链表存储。
链表的每个结点的数据域可以选择以下三种设计方式：
（1）链表的每个结点存储长整数的一位（不推荐）；
（2）链表的每个结点从长整数的低位开始拆分（4位为一组，存到一个结点中，即结点的数据域为不超过9999的非负整数），依次存放在链表的每个结点；
（3）链表的每个结点从长整数的低位开始拆分（4位为一组，存到一个结点中，即结点的数据域为1-4位字符串），依次存放在链表的每个结点。

可利用头结点的数据域存放正负数标志（正数或0：1("1")，负数：-1("-1")）。
*/

#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

list<string> inputList()
{
    string num;
    cin >> num;
    string sign;
    if (num[0] == '-')
    {
        num.erase(0, 1);
        sign = "-1";
    }
    else
        sign = "1";
    list<string> A;
    for (int i = num.length(); i > 0; i -= 4)
    {
        string temp;
        int start = max(0, i - 4);
        temp.assign(num, start, i - start);
        A.push_front(temp);
    }
    A.push_front(sign);
    return A;
};

void printList(list<string> lst)
{
    list<string>::iterator it = lst.begin();
    list<string>::iterator itr = lst.begin();
    bool isAllZero = true;
    for (it++; it != lst.end(); it++)
    {
        if (*it != "0000")
        {
            isAllZero = false;
            break;
        }
    }
    if (isAllZero)
    {
        cout << "0";
        return;
    }
    if (*itr == "-1")
    {
        cout << "-";
        itr++;
        cout << to_string(stoi(*itr++));
        for (itr; itr != lst.end(); itr++)
        {
            cout << "," << *itr;
        }
    }
    else
    {
        itr++;
        cout << to_string(stoi(*itr++));
        for (itr; itr != lst.end(); itr++)
        {
            cout << "," << *itr;
        }
    }
};

int compareAbs(list<string> A, list<string> B)
{
    A.pop_front();
    B.pop_front();
    list<string>::iterator itA = A.begin();
    list<string>::iterator itB = B.begin();
    if (A.size() > B.size())
        return 1;
    else if (A.size() < B.size())
        return -1;
    else
    {
        for (itA, itB; itA != A.end() && itB != B.end(); itA++, itB++)
        {
            if (*itA > *itB)
                return 1;
            else if (*itA < *itB)
                return -1;
        }
        return 0;
    }
}

list<string> plus(list<string> A, list<string> B) // 求A+B
{
    string sign;
    if (*A.begin() == "1")
        sign = "1";
    else
        sign = "-1";
    A.pop_front();
    B.pop_front();
    list<string> res;
    list<string>::reverse_iterator itA = A.rbegin();
    list<string>::reverse_iterator itB = B.rbegin();
    int carry = 0;
    for (itA, itB; itA != A.rend() && itB != B.rend(); itA++, itB++)
    {
        int temp = stoi(*itA) + stoi(*itB) + carry;
        carry = temp / 10000;
        temp = temp % 10000;
        stringstream ss;
        ss << setw(4) << setfill('0') << temp;
        res.push_front(ss.str());
    }
    while (itA != A.rend())
    {
        int temp = stoi(*itA) + carry;
        carry = temp / 10000;
        temp = temp % 10000;
        stringstream ss;
        ss << setw(4) << setfill('0') << temp;
        res.push_front(ss.str());
        itA++;
    }
    while (itB != B.rend())
    {
        int temp = stoi(*itB) + carry;
        carry = temp / 10000;
        temp = temp % 10000;
        stringstream ss;
        ss << setw(4) << setfill('0') << temp;
        res.push_front(ss.str());
        itB++;
    }
    if (carry != 0)
    {
        stringstream ss;
        ss << setw(4) << setfill('0') << carry;
        res.push_front(ss.str());
    }
    res.push_front(sign);
    return res;
}

list<string> minus(list<string> A, list<string> B) // 求A-B
{
    string sign;
    if (compareAbs(A, B) == 1)  // A绝对值大于B
        if (*A.begin() == "-1") // A为负,结果为负
            sign = "-1";
        else // A为正,结果为正
            sign = "1";
    else // A绝对值不大于B
    {
        if (*A.begin() == "1") // A为正,结果为负
            sign = "-1";
        else // A为负,结果为正
            sign = "1";
        list<string> temp = A; // 交换A,B
        A = B;
        B = temp;
    }
    A.pop_front();
    B.pop_front();
    list<string> res;
    list<string>::reverse_iterator itA = A.rbegin();
    list<string>::reverse_iterator itB = B.rbegin();
    int borrow = 0;
    for (itA, itB; itA != A.rend() && itB != B.rend(); itA++, itB++)
    {
        int temp = stoi(*itA) - stoi(*itB) - borrow;
        if (temp < 0)
        {
            temp += 10000;
            borrow = 1;
        }
        else
            borrow = 0;
        stringstream ss;
        ss << setw(4) << setfill('0') << temp;
        res.push_front(ss.str());
    }
    while (itA != A.rend())
    {
        int temp = stoi(*itA) - borrow;
        if (temp < 0)
        {
            temp += 10000;
            borrow = 1;
        }
        else
            borrow = 0;
        stringstream ss;
        ss << setw(4) << setfill('0') << temp;
        res.push_front(ss.str());
        itA++;
    }
    res.push_front(sign);
    return res;
}

list<string> addList(list<string> A, list<string> B)
{
    list<string> res;
    if (*A.begin() == *B.begin()) // AB同号
        res = ::plus(A, B);
    else // AB异号
        res = ::minus(A, B);
    return res;
}

int main()
{
    list<string> A = inputList();
    list<string> B = inputList();
    printList(A);
    cout << endl;
    printList(B);
    cout << endl
         << endl;
    list<string> C = addList(A, B);
    printList(C);
    return 0;
}