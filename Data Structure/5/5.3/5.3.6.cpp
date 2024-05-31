/*
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 */

#include <iostream>
#include <queue>
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

void dfs(TreeNode *root, int &ans, int depth, int &maxDepth)
{
    if (root == NULL)
        return;
    if (depth > maxDepth)
    {
        maxDepth = depth;
        ans = root->val;
    }
    dfs(root->left, ans, depth + 1, maxDepth);
    dfs(root->right, ans, depth + 1, maxDepth);
}

int main()
{
    TreeNode *root = inputTree();
    int ans = 0;
    int maxDepth = 0;
    dfs(root, ans, 1, maxDepth);
    cout << ans;
    return 0;
}
