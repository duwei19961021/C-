/*
 * 二叉树的坡度
 * 链接：https://leetcode-cn.com/problems/binary-tree-tilt/
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
    int _findTilt(TreeNode* root,int& sum)
    {
        if(root == nullptr)
            return 0;
        int left = _findTilt(root->left,sum);
        int right = _findTilt(root->right,sum);
        if(root->left == nullptr && root->right == nullptr)
        {
            sum += 0;
            return root->val;
        }
        if(root->left == nullptr && root->right != nullptr)
        {
            sum += abs(right);
            return right + root->val;
        }
        if(root->left != nullptr && root->right == nullptr)
        {
            sum += abs(left);
            return left + root->val;
        }
        sum += abs(left-right); // 更新sum的和
        return left+ right + root->val; // 返回此结点的和
    }
    int findTilt(TreeNode* root)
    {
        int sum = 0;
        _findTilt(root,sum);
        return sum;
    }
};
