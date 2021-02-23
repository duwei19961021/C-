/*
 * 路径总和
 * 链接：https://leetcode-cn.com/problems/path-sum/
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
    void _hasPathSum(TreeNode* root, int targetSum, int tmp, bool& ret)
    {
        if(root == nullptr)
        {
            ret = false;
            return;
        }
        tmp += root->val;
        if(root->left == nullptr && root->right == nullptr && tmp == targetSum) // 退出条件。递归题一定要想清楚结束递归的条件
        {
            ret = true;
            return;
        } 
        if(root->left) _hasPathSum(root->left,targetSum,tmp,ret);
        if(root->right) _hasPathSum(root->right,targetSum,tmp,ret);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ret = false;
        _hasPathSum(root,targetSum,0,ret);
        return ret;
    }
};
