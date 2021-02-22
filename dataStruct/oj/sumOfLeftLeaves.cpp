/*
 * 左叶子之和
 * 链接：https://leetcode-cn.com/problems/sum-of-left-leaves/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int ret = 0;
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) // 如果左结点不为空且这个节点的左右结点都不为空则是左叶子结点
            ret += root->left->val;
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + ret;
    }
};
