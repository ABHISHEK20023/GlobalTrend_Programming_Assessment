/*
Given a non-empty binary tree, find the maximum path sum.
A path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
The path must contain at least one node and does not need to go through the root.
The function should return an integer representing the maximum path sum.
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        maxPathDown(root, maxSum);
        return maxSum;
    }

private:
    int maxPathDown(TreeNode *node, int &maxSum)
    {
        if (node == nullptr)
            return 0;
        int leftMax = max(0, maxPathDown(node->left, maxSum));
        int rightMax = max(0, maxPathDown(node->right, maxSum));
        maxSum = max(maxSum, leftMax + rightMax + node->val);
        return max(leftMax, rightMax) + node->val;
    }
};

int main()
{
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    cout << "Maximum Path Sum: " << solution.maxPathSum(root) << std::endl;

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
