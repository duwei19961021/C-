/*
 * 二叉树的锯齿形层序遍历
 * 链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        vector<vector<int>> ret;
        if(root == nullptr)
            return ret;
        s1.push(root);
        while(!s1.empty() || !s2.empty())
        {
            while(!s1.empty())
            {
                vector<int> tmp1;
                for(int i = s1.size();i>0;i--)
                {
                    TreeNode* node = s1.top();
                    tmp1.push_back(node->val);
                    s1.pop();
                    if(node->left) s2.push(node->left);
                    if(node->right) s2.push(node->right);
                }
                ret.push_back(tmp1);
            }
            while(!s2.empty())
            {
                vector<int> tmp2;
                for(int i = s2.size();i>0;i--)
                {
                    TreeNode* node = s2.top();
                    tmp2.push_back(node->val);
                    s2.pop();
                    if(node->right) s1.push(node->right);
                    if(node->left) s1.push(node->left);
                }
                ret.push_back(tmp2);
            }
        }
        return ret;
    }
};
