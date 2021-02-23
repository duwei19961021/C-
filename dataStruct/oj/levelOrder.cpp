/*
 * 从上到下打印二叉树 II
 * 链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        if(root == nullptr)
            return ret;
        q.push(root);
        while(!q.empty())
        {
            vector<int> tmp;
            for(int i=q.size();i>0;i--){
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
