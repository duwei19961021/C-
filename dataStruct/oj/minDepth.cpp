/*
 * 二叉树的最小深度
 * 链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        if(root->left == nullptr && root->right != nullptr) // 左树为空,最小深度不是0+1,而是又子树的最小深度+1
        {
            return minDepth(root->right) + 1;
        }
        if(root->right == nullptr && root->left != nullptr)
        {
            return minDepth(root->left) + 1;
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
