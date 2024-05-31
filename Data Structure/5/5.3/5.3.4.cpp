/*
 * 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 */

#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
        if (strcmp(item, "null") != 0)
        {
            int leftNumber = atoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }
        if (count == n)
            break;
        cin >> item;
        count++;
        if (strcmp(item, "null") != 0)
        {
            int rightNumber = atoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main()
{
    TreeNode *root = inputTree();
    queue<TreeNode *> nodeQueue;
    vector<int> res;
    if (root)
        nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        int size = nodeQueue.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            if (i == size - 1)
                res.push_back(node->val);
            if (node->left)
                nodeQueue.push(node->left);
            if (node->right)
                nodeQueue.push(node->right);
        }
    }
    for (auto i : res)
        cout << i << " ";
        return 0;
}