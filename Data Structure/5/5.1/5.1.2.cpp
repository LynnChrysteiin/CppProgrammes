/*
在二叉树的二叉链表存储形式建立的基础上，使用递归的程序设计方法，设计并完成删除以元素值x为根结点的（子）树的算法。
完成后将其加入到二叉树的ADT基本操作集中。

初始条件：二叉树T存在，x是T中某个结点。

操作结果：若x是T的结点，且子树存在，则根据参数选择删除对应的子树（flag=0，删除左子树；flag=1，删除右子树）。
删除成功，返回true；否则返回false。
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
    bool destroy(BiTree<Iter> &node) // 销毁以node为根的二叉树
    {
        if (node)
        {
            destroy(node->lchild);
            destroy(node->rchild);
            delete node;
            node = nullptr;
            return true;
        }
        else
            return false;
    }
    bool destroySubTree(BiTree<Iter> &node, bool flag) // 销毁以node为根的半边子树,flag=0删除左子树，flag=1删除右子树
    {
        if (node)
            if (flag)
                return destroy(node->rchild);
            else
                return destroy(node->lchild);
        return false;
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
    BiTNode<Iter> *findByValue(BiTree<Iter> &node, const Iter &elem) // 查找值为elem的结点
    {
        if (node)
        {
            if (node->data == elem)
                return node;
            else
            {
                auto left = findByValue(node->lchild, elem);
                if (left)
                    return left;
                else
                    return findByValue(node->rchild, elem);
            }
        }
        return nullptr;
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
    std::string x;
    std::cin >> x;
    bool flag;
    std::cin >> flag;

    tree.preOrder(root);
    std::cout << std::endl;
    tree.setFirstPrint().inOrder(root);
    std::cout << std::endl;
    tree.setFirstPrint().postOrder(root);
    std::cout << std::endl
              << std::endl;

    BiTNode<std::string> *node = tree.findByValue(root, x);
    if (tree.destroySubTree(node, flag))
    {
        std::cout << "true" << std::endl
                  << std::endl;
        tree.setFirstPrint().preOrder(root);
        std::cout << std::endl;
        tree.setFirstPrint().inOrder(root);
        std::cout << std::endl;
        tree.setFirstPrint().postOrder(root);
    }
    else
        std::cout << "false";
    return 0;
}