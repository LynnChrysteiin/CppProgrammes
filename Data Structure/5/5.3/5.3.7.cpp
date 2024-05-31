/*
 * 给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。
 * 如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（输出顺序由小到大）。
 * 一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>
#include <algorithm>
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

vector<int> findFrequentTreeSum(TreeNode *root)
{
    unordered_map<int, int> sumMap;
    vector<int> res;
    int maxCount = 0;
    function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int
    {
        if (node == NULL)
            return 0;
        int sum = node->val + dfs(node->left) + dfs(node->right);
        sumMap[sum]++;
        maxCount = max(maxCount, sumMap[sum]);
        return sum;
    };
    dfs(root);
    for (auto &item : sumMap)
    {
        if (item.second == maxCount)
            res.push_back(item.first);
    }
    return res;
}

int main()
{
    TreeNode *root = inputTree();
    vector<int> res = findFrequentTreeSum(root);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}