/*
 * 二叉树的直径 (节点左右子树的最大深度的和)
 * 链接：https://leetcode-cn.com/problems/diameter-of-binary-tree/
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
    int max = 0;
    int _diameterOfBinaryTree(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int leftDepth = 0;
        if(root->left)
            leftDepth = _diameterOfBinaryTree(root->left) + 1;
        int rightDepth = 0;
        if(root->right)
            rightDepth = _diameterOfBinaryTree(root->right) + 1;
        max = max > leftDepth+rightDepth ? max:leftDepth+rightDepth; // 更新全局的max
        return leftDepth > rightDepth ? leftDepth:rightDepth;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        _diameterOfBinaryTree(root);
        return max;
    }
};

// cout << "root = " << root->val << "," << "depth = " << Depth << endl;
