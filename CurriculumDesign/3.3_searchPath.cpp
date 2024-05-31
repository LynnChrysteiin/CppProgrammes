/* 
 * ʵ���� ����������������Ľڵ�·��
 *
 * ����������
 * ����һ�ö����������ʵ�ִӸ���㵽�������֮���·����
 *
 * ����Ҫ��
 * ����һ���Զ�������洢�Ķ���������btָ����ڵ㡢pָ����һ������㣬���ʵ�֡����ַ���ʽ����Ӹ���㵽�������֮���·������
 *
 * �������ݣ�
 * ���н���һ�������� ��A��B��C��D��E��F��G��H��I��J�� �е�Ӣ����ĸΪ��������һ�ö�������
 *
 * ʵ����ʾ��
 * ��1����ĳ�ֱ�����ʽ�����������Ķ�������洢�ṹ��
 * ��2���Էǵݹ�ĺ���ʽ����������bt���������ʹ��Ľ�����δ洢��һ��˳��ջS�У�
 * ��3��������������ʵ����*pʱ����ʱջS�д�ŵ����н���Ϊ�������*p�����ȣ�������Щ���ȣ��㹹����һ���Ӹ���㵽���*p֮���·����
 *
 * ѡ�����ݣ�
 * ��1����Ӹ���㵽�������֮��·���ĳ��ȡ�
 * ��2���������ֲ�ͬ�ı�����ʽ����������������ʽ�洢�ṹ��
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

    bool isEmpty() const // �ж϶������Ƿ�Ϊ��
    {
        return root == nullptr;
    }

    bool destroy(BiTree<Iter> &node) // ������nodeΪ���Ķ�����
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

    BiTree<Iter> &getRoot() // ��ȡ�����
    {
        return root;
    }

    void preOrderCreateWithMark(BiTree<Iter> &node, Iter mark) // ǰ�򴴽���������markΪ���, ���ڱ�ǿս��
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

    void levelOrderCreateWithMark(BiTree<Iter> &node, Iter mark) // ��δ�����������markΪ���, ���ڱ�ǿս��
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

    // �������ڵ㵽�������֮���·��
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
     * ǰ�򴴽�: A B # C D # E # # F # # G # H # I J # # #
     * ��δ���: A B G # C # H D F # I # E # # J # # # # #
     * '#' ���ڱ�ǿս��
     */

    std::cout << "********************�� �� �� �� �� �� �� ��********************" << std::endl;
    std::cout << "****         ʵ����   ������   ��������Ͻ��·��          ****" << std::endl;
    std::cout << "***************************************************************" << std::endl
              << std::endl;

    BiTreeADT<char> tree;
    bool isInputCorrect = false;
    while (!isInputCorrect)
    {
        char inputType;
        std::cout << "��������ĸѡ�񴴽���ʽ��ǰ��'P'/���'L'/�˳�'E'����";
        std::cin >> inputType;

        switch (inputType)
        {
        case 'P':
            std::cout << "������ǰ�����У�'#'����ս�㣩��";
            tree.preOrderCreateWithMark(tree.getRoot(), '#');
            isInputCorrect = true;
            break;
        case 'L':
            std::cout << "�����������У�'#'����ս�㣩��";
            tree.levelOrderCreateWithMark(tree.getRoot(), '#');
            isInputCorrect = true;
            break;
        case 'E':
            return 0;
        default:
            std::cout << "�������" << std::endl;
            break;
        }
    }

    isInputCorrect = false;
    while (!isInputCorrect)
    {
        char node;
        std::cout << "������Ҫ�����Ľ�㣺������0�˳���";
        std::cin >> node;
        if (node == '0')
            break;
        std::vector<char> path;
        path = tree.searchPath(tree.getRoot(), node);
        unsigned int pathLength = path.size() - 1;

        if (path.size() == 0)
        {
            std::cout << "δ�ҵ��ý�㣡" << std::endl
                      << std::endl;
        }
        else
        {
            std::cout << "·��Ϊ��";
            for (auto iter = path.rbegin(); iter != path.rend(); ++iter)
            {
                std::cout << *iter << " ";
            }
            std::cout << std::endl
                      << "·������Ϊ��" << pathLength << std::endl
                      << std::endl;
        }
    }
    return 0;
}
