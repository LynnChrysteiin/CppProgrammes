/*
 * 给定一个完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。
 *
 * 二叉树定义如下：
 * struct Node
 * {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *next;
 * }
 *
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 * 初始状态下，所有 next 指针都被设置为 NULL。
 */

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *inputTree()
{
    int n, count = 0;
    char item[100];
    cin >> n;
    if (n == 0)
        return NULL;
    cin >> item;
    TreeNode *root = new TreeNode(atoi(item));
    count++;
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    while (count < n)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();
        cin >> item;
        count++;
        int leftNumber = atoi(item);
        node->left = new TreeNode(leftNumber);
        nodeQueue.push(node->left);
        if (count == n)
            break;
        cin >> item;
        count++;
        int rightNumber = atoi(item);
        node->right = new TreeNode(rightNumber);
        nodeQueue.push(node->right);
    }
    return root;
}

void fillNext(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        int size = nodeQueue.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *tmp = nodeQueue.front();
            nodeQueue.pop();
            if (i < size - 1)
                tmp->next = nodeQueue.front();
            if (tmp->left)
                nodeQueue.push(tmp->left);
            if (tmp->right)
                nodeQueue.push(tmp->right);
        }
    }
}

void leverOrder(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> leftNodeQueue;
    auto leftNode = root;
    while (leftNode)
    {
        leftNodeQueue.push(leftNode);
        leftNode = leftNode->left;
    }
    while (!leftNodeQueue.empty())
    {
        auto node = leftNodeQueue.front();
        while (node)
        {
            cout << node->val << " ";
            node = node->next;
        }
        cout << "# ";
        leftNodeQueue.pop();
    }
}

int main()
{
    auto tree = inputTree();
    fillNext(tree);
    leverOrder(tree);
    return 0;
}