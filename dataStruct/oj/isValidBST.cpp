/**
 * 验证二叉搜索树
 * 链接：https://leetcode-cn.com/problems/validate-binary-search-tree/
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

// 搜索树的中序遍历是有序的

class Solution {
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root)
    {
        if(root == nullptr)
        {
            return true;
        }
        bool leftRet = isValidBST(root->left);
        if(pre && pre->val >= root->val)
        {
            return false;
        }
        pre = root; //保存上一个结点
        bool rightRet = isValidBST(root->right);
        return leftRet && rightRet;
    }
};
