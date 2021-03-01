/**
 * 合并二叉树
 * 链接：https://leetcode-cn.com/problems/merge-two-binary-trees/
 /

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
    {
        if(root1 == nullptr && root2 == nullptr) // 其中一个结点为空则需要合并，只有同时为空时才不需要合并
        {
            return nullptr;
        }

		// 退出条件为：root1 root2 同时为空，因此走到这里 roo1 或者 root2 其中可能会是空结点(也可能都不为空)
        int val1 = root1 == nullptr ? 0 : root1->val; // 取值时先判断是否为空
        int val2 = root2 == nullptr ? 0 : root2->val;
        TreeNode* ret = new TreeNode(val1+val2);
        ret->left = mergeTrees(root1 == nullptr ? nullptr:root1->left, root2 == nullptr ? nullptr:root2->left); // 递归时也要判断是否存在空结点
        ret->right = mergeTrees(root1 == nullptr ? nullptr:root1->right,root2 == nullptr ? nullptr:root2->right);
        return ret;
    }
};
