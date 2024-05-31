/*
目的：使用C++模板设计并逐步完善二叉树的抽象数据类型（ADT）。
内容：
（1）请参照链表的ADT模板，设计二叉树并逐步完善的抽象数据类型。
    （由于该环境目前仅支持单文件的编译，故将所有内容都集中在一个源文件内。
    在实际的设计中，推荐将抽象类及对应的派生类分别放在单独的头文件中。
    参考教材、课件，以及网盘中的链表ADT原型文件，自行设计二叉树的ADT。）
注意：二叉树ADT的基本操作的算法设计很多要用到递归的程序设计方法。

（2）基本操作1：二叉树的二叉链表存储形式的建立，完成后将其加入到二叉树的ADT基本操作集中。

要求设计一个递归算法，将二叉树转化为二叉链表的存储形式。

初始条件：definition给出二叉树T的定义（先序序列。无孩子或指针为空的情形，算法通过特殊分隔符识别（输入）），至少有1个根结点。
输出：按definition构造二叉树的二叉链表。
注意：由于测试数据的显示需建立在二叉树的遍历基础上。因此，请在设计好二叉树的三种遍历算法之后（基本操作2），再进行测试。

输入:
null
A B null C D null null E null null F null G null H null null

输出:
A,B,C,D,E,F,G,H
B,D,C,E,A,F,G,H
D,E,C,B,H,G,F,A
*/

#include <iostream>
#include <string>

template <class Iter>
struct BiTNode
{
    Iter data;
    BiTNode *lchild, *rchild;
};

template <class Iter>
using BiTree = BiTNode<Iter> *;

template <class Iter>
class BiTreeADT
{
private:
    BiTree<Iter> root;
    bool firstPrint = true;

public:
    BiTreeADT() : root(nullptr) {}
    BiTreeADT(const Iter &elem) : root(new BiTNode<Iter>{elem, nullptr, nullptr}) {}
    ~BiTreeADT() { destroy(root); }
    void destroy(BiTree<Iter> &node) // 销毁二叉树
    {
        if (node)
        {
            destroy(node->lchild);
            destroy(node->rchild);
            delete node;
            node = nullptr;
        }
    }
    BiTree<Iter> &getRoot()
    {
        return root;
    }
    BiTreeADT<Iter> &setFirstPrint()
    {
        firstPrint = true;
        return *this;
    }
    void visitNode(BiTNode<Iter> *node) // 访问结点
    {
        if (firstPrint)
            firstPrint = false;
        else
            std::cout << ",";
        std::cout << node->data;
    }
    void preOrder(BiTNode<Iter> *node) // 前序遍历
    {
        if (node)
        {
            visitNode(node);
            preOrder(node->lchild);
            preOrder(node->rchild);
        }
    }
    void inOrder(BiTNode<Iter> *node) // 中序遍历
    {
        if (node)
        {
            inOrder(node->lchild);
            visitNode(node);
            inOrder(node->rchild);
        }
    }
    void postOrder(BiTNode<Iter> *node) // 后序遍历
    {
        if (node)
        {
            postOrder(node->lchild);
            postOrder(node->rchild);
            visitNode(node);
        }
    }
    void preOrderCreate(BiTree<Iter> &node, Iter sep)
    {
        Iter elem;
        std::cin >> elem;
        if (elem == sep)
            node = nullptr;
        else
        {
            node = new BiTNode<Iter>{elem, nullptr, nullptr};
            preOrderCreate(node->lchild, sep);
            preOrderCreate(node->rchild, sep);
        }
    }
};

int main()
{
    std::string sep;
    std::cin >> sep;
    BiTreeADT<std::string> tree;
    auto root = tree.getRoot();
    tree.preOrderCreate(root, sep);
    tree.preOrder(root);
    std::cout << std::endl;
    tree.setFirstPrint().inOrder(root);
    std::cout << std::endl;
    tree.setFirstPrint().postOrder(root);
    return 0;
}