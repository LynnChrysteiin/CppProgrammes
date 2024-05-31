/*
 * 给定一个二叉树的root，输出最长的路径的长度，这个路径中的每个节点具有相同值 。
 * 这条路径可以经过也可以不经过根节点。
 * 两个节点之间的路径长度由它们之间的边数表示。
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

int findPath(TreeNode *root, int &maxPath)
{
    if (root == NULL)
        return 0;
    int nleft = root->left ? findPath(root->left, maxPath) : 0;
    int nright = root->right ? findPath(root->right, maxPath) : 0;
    nleft = (root->left != NULL && root->left->val == root->val) ? nleft + 1 : 0;
    nright = (root->right != NULL && root->right->val == root->val) ? nright + 1 : 0;
    maxPath = max(maxPath, nleft + nright);
    return max(nleft, nright);
}

void dfs(TreeNode *root, int &ans)
{
    if (root == NULL)
        return;
    dfs(root->left, ans);
    dfs(root->right, ans);
    findPath(root, ans);
}

int main()
{
    TreeNode *root = inputTree();
    int ans = 0;
    dfs(root, ans);
    cout << ans;
    return 0;
}
