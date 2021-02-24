/*
 * 二叉树的中序遍历
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
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

 /*
class Solution {
public:
    void _inorderTraversal(TreeNode* root, vector<int>& ret)
    {
        if(root == nullptr)
            return;
        _inorderTraversal(root->left,ret);
        ret.push_back(root->val);
        _inorderTraversal(root->right,ret);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        _inorderTraversal(root,ret);
        return ret;
    }
};
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ret;
        stack<TreeNode*> s;
        if(root == nullptr)
            return ret;
        TreeNode* cur = root;
        while(!s.empty() || cur != nullptr)
        {
            while(cur != nullptr)
            {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            ret.push_back(cur->val);
            cur = cur->right;
        }
        return ret;
    }
};
