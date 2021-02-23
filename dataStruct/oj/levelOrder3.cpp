/*
 * 从上到下打印二叉树 III
 * 链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        stack<TreeNode*> q1;
        stack<TreeNode*> q2;
        if(root == nullptr)
            return ret;
        q1.push(root);
        while(!q1.empty() || !q2.empty())
        {
            if(!q1.empty())
            {
                vector<int> tmp;
                for(int i = q1.size(); i > 0;i--)
                {
                    TreeNode* node = q1.top();
                    q1.pop();
                    tmp.push_back(node->val);
                    if(node->left != nullptr) q2.push(node->left);
                    if(node->right != nullptr) q2.push(node->right);
                }
                ret.push_back(tmp);
            }

            if(!q2.empty())
            {
                vector<int> tmp;
                for(int i = q2.size(); i > 0;i--)
                {
                    TreeNode* node = q2.top();
                    q2.pop();
                    tmp.push_back(node->val);
                    if(node->right != nullptr) q1.push(node->right);
                    if(node->left != nullptr) q1.push(node->left);
                }
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};
