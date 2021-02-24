/*
 * 二叉搜索树的范围和
 * 链接：https://leetcode-cn.com/problems/range-sum-of-bst/
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

// 平衡树，一个结点的左子树上的值全比他自己的值小，右子树上的值全比他自己大
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        if (root == nullptr) {
            return 0;
        }
        if (root->val < low){ // 当前结点的值小于low则左子树可以直接排除掉
            return rangeSumBST(root->right,low,high);
        }
        if (root->val > high){ // 同理
            return rangeSumBST(root->left,low,high);
        }
        return rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high)+root->val;
    }
};
