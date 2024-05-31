/*
 * ����һ�ö����� root����������ظ�������������
 * ���������������ͬ�Ľṹ����ͬ�Ľ��ֵ�����������ظ��ġ�
 * ���������������������ĸ�+������+��������������������Ϊ�գ��ṹ�����ֵ����ͬ��
 */

#include <iostream>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>
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

string collect(TreeNode *node, vector<TreeNode *> &res)
{
    static unordered_map<string, int> count;
    if (!node)
        return "null";
    string serial = to_string(node->val) + "," + collect(node->left, res) + "," + collect(node->right, res);
    count[serial]++;
    if (count[serial] == 2)
        res.push_back(node);
    return serial;
}

int main()
{
    TreeNode *root = inputTree();
    vector<TreeNode *> res;
    collect(root, res);
    cout << res.size() << endl;
    return 0;
}