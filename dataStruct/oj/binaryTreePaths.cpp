/*
 * 二叉树的所有路径
 * 链接：https://leetcode-cn.com/problems/binary-tree-paths/
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
    void _binaryTreePaths(TreeNode* root, vector<string>& ret,string tmp)
    {
        if(root == nullptr) return;
        tmp.append(to_string(root->val)+"->");
        if(root->left == nullptr && root->right == nullptr)
        {
            tmp.erase(tmp.end()-2,tmp.end());
            ret.push_back(tmp);
            return;
        }
        if(root->left) _binaryTreePaths(root->left,ret,tmp);
        if(root->right) _binaryTreePaths(root->right,ret,tmp);
    }

    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> ret;
        string tmp;
        _binaryTreePaths(root,ret,tmp);
        return ret;
    }
};
