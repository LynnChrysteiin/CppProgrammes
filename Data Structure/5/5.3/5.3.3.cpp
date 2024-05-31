/*
 * 给定一个不重复的整数数组 nums 。
 * 最大二叉树 可以用下面的算法从 nums 递归地构建:
 * 创建一个根节点，其值为 nums 中的最大值。
 * 递归地在最大值 左边 的 子数组构建左子树。
 * 递归地在最大值 右边 的 子数组构建右子树。
 * 返回 nums 构建的 最大二叉树 。
 */

#include <iostream>
#include <vector>
#include <queue>

struct BiTNode
{
    int val;
    BiTNode *left;
    BiTNode *right;

    BiTNode() : val(0), left(NULL), right(NULL) {}
    BiTNode(int x) : val(x), left(NULL), right(NULL) {}
    BiTNode(int x, BiTNode *left, BiTNode *right) : val(x), left(left), right(right) {}
};

inline std::vector<int>::iterator findMaxIter(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    std::vector<int>::iterator maxIter = begin;
    for (auto iter = begin; iter != end; iter++)
    {
        if (*iter > *maxIter)
            maxIter = iter;
    }
    return maxIter;
}

BiTNode *buildMaxBiTree_Cursive(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (begin == end)
        return nullptr;
    auto maxIter = findMaxIter(begin, end);
    BiTNode *root = new BiTNode(*maxIter);
    root->left = buildMaxBiTree_Cursive(begin, maxIter);
    root->right = buildMaxBiTree_Cursive(maxIter + 1, end);
    return root;
}

void buildMaxBiTree(std::vector<int> nums, BiTNode *&root)
{
    root = buildMaxBiTree_Cursive(nums.begin(), nums.end());
}

void levelOrder(BiTNode *root)
{
    std::queue<BiTNode *> q;
    q.push(root);
    while (!q.empty())
    {
        BiTNode *node = q.front();
        q.pop();
        if (node)
        {
            std::cout << node->val << " ";
            if (node->left)
            {
                q.push(node->left);
                if (!node->right)
                    q.push(nullptr);
            }
            if (node->right)
            {
                if (!node->left)
                    q.push(nullptr);
                q.push(node->right);
            }
        }
        else
            std::cout << "null ";
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
    }
    BiTNode *root;
    buildMaxBiTree(nums, root);
    levelOrder(root);
    return 0;
}