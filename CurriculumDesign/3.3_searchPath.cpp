/* 
 * 实践三 课题三：求二叉树的节点路径
 *
 * 问题描述：
 * 建立一棵二叉树，编程实现从根结点到给定结点之间的路径。
 *
 * 基本要求：
 * 建立一棵以二叉链表存储的二叉树，以bt指向根节点、p指向任一给定结点，编程实现“以字符形式输出从根结点到给定结点之间的路径”。
 *
 * 测试数据：
 * 自行建立一棵以序列 ｛A，B，C，D，E，F，G，H，I，J｝ 中的英文字母为结点的任意一棵二叉树。
 *
 * 实现提示：
 * （1）以某种遍历方式建立二叉树的二叉链表存储结构；
 * （2）以非递归的后序方式遍历二叉树bt，并将访问过的结点依次存储到一个顺序栈S中；
 * （3）当后序遍历访问到结点*p时，此时栈S中存放的所有结点均为给定结点*p的祖先，而由这些祖先，便构成了一条从根结点到结点*p之间的路径。
 *
 * 选做内容：
 * （1）求从根结点到给定结点之间路径的长度。
 * （2）试以两种不同的遍历方式，建立二叉树的链式存储结构。
 */

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>

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

    BiTree<Iter> &getRoot() // 获取根结点
    {
        return root;
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

    void levelOrderCreateWithMark(BiTree<Iter> &node, Iter mark) // 层次创建二叉树，mark为标记, 用于标记空结点
    {
        getchar();
        std::stringstream ss;
        std::string str;
        std::getline(std::cin, str);
        ss << str;

        Iter rootElem;
        ss >> rootElem;
        node = new BiTNode<Iter>{rootElem, nullptr, nullptr};
        std::queue<BiTNode<Iter> *> Q;
        Q.push(node);
        Iter elem;
        bool isLeft = true;
        while (ss >> elem)
        {
            auto front = Q.front();
            if (elem != mark)
            {
                auto child = new BiTNode<Iter>{elem, nullptr, nullptr};
                Q.push(child);
                if (isLeft)
                    front->lchild = child;
                else
                    front->rchild = child;
            }
            if (!isLeft)
                Q.pop();
            isLeft = !isLeft;
        }
    }

    // 搜索根节点到给定结点之间的路径
    std::vector<Iter> searchPath(BiTree<Iter> &node, const Iter &elem)
    {
        std::vector<Iter> path;
        std::stack<BiTNode<Iter> *> S;
        BiTNode<Iter> *p = node, *r = nullptr;
        while (p || !S.empty())
        {
            if (p)
            {
                S.push(p);
                if (p->data == elem)
                {
                    while (!S.empty())
                    {
                        path.push_back(S.top()->data);
                        S.pop();
                    }
                    break;
                }
                p = p->lchild;
            }
            else
            {
                p = S.top();
                if (p->rchild && p->rchild != r)
                    p = p->rchild;
                else
                {
                    r = p;
                    S.pop();
                    p = nullptr;
                }
            }
        }
        return path;
    }
};

int main()
{
    /*
     * 前序创建: A B # C D # E # # F # # G # H # I J # # #
     * 层次创建: A B G # C # H D F # I # E # # J # # # # #
     * '#' 用于标记空结点
     */

    std::cout << "********************数 据 结 构 课 程 设 计********************" << std::endl;
    std::cout << "****         实践五   课题三   求二叉树上结点路径          ****" << std::endl;
    std::cout << "***************************************************************" << std::endl
              << std::endl;

    BiTreeADT<char> tree;
    bool isInputCorrect = false;
    while (!isInputCorrect)
    {
        char inputType;
        std::cout << "请输入字母选择创建方式（前序'P'/层次'L'/退出'E'）：";
        std::cin >> inputType;

        switch (inputType)
        {
        case 'P':
            std::cout << "请输入前序序列（'#'代表空结点）：";
            tree.preOrderCreateWithMark(tree.getRoot(), '#');
            isInputCorrect = true;
            break;
        case 'L':
            std::cout << "请输入层次序列（'#'代表空结点）：";
            tree.levelOrderCreateWithMark(tree.getRoot(), '#');
            isInputCorrect = true;
            break;
        case 'E':
            return 0;
        default:
            std::cout << "输入错误！" << std::endl;
            break;
        }
    }

    isInputCorrect = false;
    while (!isInputCorrect)
    {
        char node;
        std::cout << "请输入要搜索的结点：（输入0退出）";
        std::cin >> node;
        if (node == '0')
            break;
        std::vector<char> path;
        path = tree.searchPath(tree.getRoot(), node);
        unsigned int pathLength = path.size() - 1;

        if (path.size() == 0)
        {
            std::cout << "未找到该结点！" << std::endl
                      << std::endl;
        }
        else
        {
            std::cout << "路径为：";
            for (auto iter = path.rbegin(); iter != path.rend(); ++iter)
            {
                std::cout << *iter << " ";
            }
            std::cout << std::endl
                      << "路径长度为：" << pathLength << std::endl
                      << std::endl;
        }
    }
    return 0;
}
