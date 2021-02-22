/*
 * 对称二叉树
 * 链接：https://leetcode-cn.com/problems/symmetric-tree/
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

class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        return dfs(root->left,root->right);
    }
    
    bool dfs(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right == nullptr) // 首先要思考退出的条件：左树和右树同时为空返回true
            return true;
        if(left == nullptr || right == nullptr) // 左右树只有其中一个为空则返回false
            return false;
        if(left->val != right->val) // 左树右树的值不相等返回fasle
            return false;
        return dfs(left->left,right->right) && dfs(left->right,right->left); 
    }
};
