/*
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 */

#include <iostream>
#include <cstring>
#include <queue>

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

void countLeftLeaf(TreeNode *root, int &res, bool isLeft)
{
    if (root == NULL)
        return;
    countLeftLeaf(root->left, res, true);
    countLeftLeaf(root->right, res, false);
    if (root->left == NULL && root->right == NULL && isLeft)
        res += root->val;
}

int main()
{
    TreeNode *root = inputTree();
    int res = 0;
    countLeftLeaf(root, res, false);
    cout << res;
    return 0;
}