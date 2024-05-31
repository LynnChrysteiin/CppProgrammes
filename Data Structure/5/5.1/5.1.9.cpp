/*
要求设计一个递归算法，将二叉树中所有结点左、右子树相互交换。
*/

#include <iostream>
#include <string>
#include <queue>

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
    bool isEmpty() const // 判断二叉树是否为空
    {
        return root == nullptr;
    }
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
    bool insertChildTree(BiTree<Iter> &node, bool flag, BiTree<Iter> &child) // 在node节点下插入子树, 原child节点右子树为空, 原node节点的左/右子树成为child的右子树
    {
        if (node)
        {
            if (flag)
            {
                child->rchild = node->rchild;
                node->rchild = child;
            }
            else
            {
                child->rchild = node->lchild;
                node->lchild = child;
            }
            return true;
        }
        return false;
    }
    BiTree<Iter> &getRoot() // 获取根结点
    {
        return root;
    }
    BiTreeADT<Iter> &setFirstPrint() // 设置firstPrint为true, 为了不输出第一个逗号
    {
        firstPrint = true;
        return *this;
    }
    BiTNode<Iter> *findByValue(BiTree<Iter> &node, const Iter &elem) // 在node结点以下查找值为elem的结点
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
    BiTNode<Iter> *findParent(BiTree<Iter> &node, BiTNode<Iter> *childNode) // 在node节点下查找childNode结点的父结点
    {
        if (node)
        {
            if (node->lchild == childNode || node->rchild == childNode)
                return node;
            else
            {
                auto left = findParent(node->lchild, childNode);
                if (left)
                    return left;
                else
                    return findParent(node->rchild, childNode);
            }
        }
        return nullptr;
    }
    bool leafCount(BiTNode<Iter> *node, int &count) // 统计叶子结点的数目
    {
        if (node)
        {
            if (!node->lchild && !node->rchild)
                count++;
            leafCount(node->lchild, count);
            leafCount(node->rchild, count);
            return true;
        }
        return false;
    }
    bool getHeight(BiTNode<Iter> *node, int &height) // 获取以elem为根结点的子树的高度
    {
        int leftHeight = 0, rightHeight = 0;
        if (node)
        {
            getHeight(node->lchild, leftHeight);
            getHeight(node->rchild, rightHeight);
            height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
            return true;
        }
        return false;
    }
    void swapChildTree(BiTree<Iter> &node) // 交换node节点的左右子树
    {
        if (node)
        {
            swapChildTree(node->lchild);
            swapChildTree(node->rchild);
            auto temp = node->lchild;
            node->lchild = node->rchild;
            node->rchild = temp;
        }
    }
    bool visitNode(BiTNode<Iter> *node) // 访问结点
    {
        if (!node)
            return false;
        if (firstPrint)
            firstPrint = false;
        else
            std::cout << ",";
        std::cout << node->data;
        return true;
    }
    bool preOrder(BiTNode<Iter> *node) // 前序遍历
    {
        if (node)
        {
            visitNode(node);
            preOrder(node->lchild);
            preOrder(node->rchild);
            return true;
        }
        return false;
    }
    bool inOrder(BiTNode<Iter> *node) // 中序遍历
    {
        if (node)
        {
            inOrder(node->lchild);
            visitNode(node);
            inOrder(node->rchild);
            return true;
        }
        return false;
    }
    bool postOrder(BiTNode<Iter> *node) // 后序遍历
    {
        if (node)
        {
            postOrder(node->lchild);
            postOrder(node->rchild);
            visitNode(node);
            return true;
        }
        return false;
    }
    bool layerOrder(BiTNode<Iter> *node) // 层次遍历
    {
        if (!node)
            return false;
        std::queue<BiTNode<Iter> *> Q;
        Q.push(node);
        while (!Q.empty())
        {
            auto front = Q.front();
            Q.pop();
            if (!visitNode(front))
                return false;
            if (front->lchild)
                Q.push(front->lchild);
            if (front->rchild)
                Q.push(front->rchild);
        }
        return true;
    }
    void preOrderCreateWithMark(BiTree<Iter> &node, Iter mark) // 前序创建二叉树，mark为标记, 用于标记空结点
    {
        Iter elem;
        std::cin >> elem;
        if (elem == mark)
            node = nullptr;
        else
        {
            node = new BiTNode<Iter>{elem, nullptr, nullptr};
            preOrderCreateWithMark(node->lchild, mark);
            preOrderCreateWithMark(node->rchild, mark);
        }
    }
};

int main()
{
    std::string mark;
    std::cin >> mark;
    BiTreeADT<std::string> tree;
    tree.preOrderCreateWithMark(tree.getRoot(), mark);

    tree.preOrder(tree.getRoot());
    std::cout << std::endl;
    tree.setFirstPrint().inOrder(tree.getRoot());
    std::cout << std::endl;
    tree.setFirstPrint().postOrder(tree.getRoot());
    std::cout << std::endl
              << std::endl;

    tree.swapChildTree(tree.getRoot());
    tree.setFirstPrint().preOrder(tree.getRoot());
    std::cout << std::endl;
    tree.setFirstPrint().inOrder(tree.getRoot());
    std::cout << std::endl;
    tree.setFirstPrint().postOrder(tree.getRoot());
    
    return 0;
}