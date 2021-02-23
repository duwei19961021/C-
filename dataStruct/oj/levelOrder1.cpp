/*
 * 从上到下打印二叉树
 * 链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
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
    vector<int> levelOrder(TreeNode* root) 
    {
        vector<int> ret;
        queue<TreeNode*> q;
        if(root == nullptr)
            return ret;
        q.push(root);
        while(!q.empty())
        {
            ret.push_back(q.front()->val);
            if(q.front()->left != nullptr)
            {
                q.push(q.front()->left);
            }
            if(q.front()->right != nullptr)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
        return ret;
    }
};
