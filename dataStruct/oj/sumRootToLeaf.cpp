/*
 * 从根到叶的二进制数之和
 * 链接：https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers/
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
class Solution { // 先序遍历
public:
    int calVector(vector<int>& v)
    {
        int flag = 1;
        int ret = 0;
        for(int i = v.size()-1; i >= 0; i--)
        {
            ret += (v[i]*flag);
            flag*=2;
        }
        return ret;
    }

    void dfs(TreeNode* root,int& result,vector<int> tmp) // tmp是值传递，下层递归完时返回上一层不影响上一层的值
    {
        tmp.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            result+=calVector(tmp);
            return;
        }
        if(root->left) dfs(root->left,result,tmp); // 左不为空则往左走一直走到空为止
        if(root->right) dfs(root->right,result,tmp);
    }

    int sumRootToLeaf(TreeNode* root)
    {
        int result = 0;;
        vector<int> One;
        dfs(root,result,One);
        return result;
    }
};
