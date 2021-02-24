/*
 * 二叉树的层平均值
 * 链接：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
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

// 利用队列层序遍历
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> ret;
        queue<TreeNode*> q;
        if(root == nullptr)
            return ret;
        q.push(root);
        while(!q.empty())
        {
            double levelSum = 0;
            int size = q.size();
            for(int i = size; i > 0; i--)
            {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ret.push_back(levelSum/size);
        }
        return ret;
    }
};
