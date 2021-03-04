/**
 * 从叶结点开始的最小字符串
 * 链接：https://leetcode-cn.com/problems/smallest-string-starting-from-leaf/
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

// 深度优先,将每个子串保存进入vector,再找出最小的


class Solution {
public:
    void dfs(TreeNode* root, vector<string>& v, string& s)
    {
        if(root == nullptr)
        {
            return;
        }
        s.insert(s.begin(),root->val+'a');
        if(root->left == nullptr && root->right == nullptr)
        {
            v.push_back(s);
        }
        dfs(root->left,v,s);
        dfs(root->right,v,s);
        s.erase(s.begin());
    }

    string smallestFromLeaf(TreeNode* root)
    {
        string s;
        vector<string> v;
        dfs(root,v,s);

        string min = v[0];
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] < min)
            {
                min = v[i];
            }
        }
        return min;
    }
};
