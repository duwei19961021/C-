/*
 * 求根到叶子节点数字之和
 * 链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/submissions/
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

// 前序遍历

class Solution {
public:
    long cal(vector<int>& v)
    {
        long flag = 1;
        long ret = 0;
        for(auto it = v.rbegin(); it != v.rend(); it++)
        {
            ret += (*it * flag);
            flag *= 10;
        }
        return ret;
    }

    void _sumNumbers(TreeNode* root,vector<int> tmp,long& ret)
    {
        if(root == nullptr)
        {
            return;
        }
        tmp.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            ret += cal(tmp);
            return;
        }
        _sumNumbers(root->left,tmp,ret);
        _sumNumbers(root->right,tmp,ret);
    }

    int sumNumbers(TreeNode* root)
    {
        long ret = 0;
        vector<int> tmp;
        _sumNumbers(root,tmp,ret);
        return ret;
    }
};
