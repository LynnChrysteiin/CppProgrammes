/*
 * 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
 */

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

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

vector<int> findMaxOfLevel(TreeNode *root)
{
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    vector<int> res;
    while (!nodeQueue.empty())
    {
        int size = nodeQueue.size();
        int max = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();
            if (node->val > max)
                max = node->val;
            if (node->left)
                nodeQueue.push(node->left);
            if (node->right)
                nodeQueue.push(node->right);
        }
        res.push_back(max);
    }
    return res;
}

int main()
{
    TreeNode *root = inputTree();
    vector<int> max = findMaxOfLevel(root);
    for (auto i : max)
        cout << i << " ";
    return 0;
}