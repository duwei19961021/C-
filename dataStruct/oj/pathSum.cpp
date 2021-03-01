/**
 * 路径总和 II
 * 链接：https://leetcode-cn.com/problems/path-sum-ii/
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

// dfs,遍历所有路径判断和是否等于target
class Solution {
public:
    void dfs(TreeNode* root, vector<vector<int>>& ret, vector<int>& tmp, int targetSum)
    {
        if(root == nullptr)
        {
            return;
        }
        tmp.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && accumulate(tmp.begin(),tmp.end(),0) == targetSum)
        {
                ret.push_back(tmp);
        }

        if(root->left)
        {
            dfs(root->left,ret,tmp,targetSum);
        }
        if(root->right)
        {
            dfs(root->right,ret,tmp,targetSum);
        }
        tmp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ret;
        vector<int> tmp;
        dfs(root,ret,tmp,targetSum);
        return ret;
    }
};
