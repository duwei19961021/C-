/**
 * 二叉树的镜像
 * 链接：https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
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

/**
 * 右 -> 中 -> 左
 * 递归到右子树的终点(此时左右子树都为空)，将root的左子树给ret的右子树，右子树给左子树，然后递归到上一层，
 * 将左子树给右子树....
 */

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) 
    {
         if(root == nullptr)
         {
             return nullptr;
         }
         TreeNode* ret = new TreeNode;
         ret->val = root->val;
         TreeNode* r =  mirrorTree(root->right);
         TreeNode* l = mirrorTree(root->left);
         ret->right = l;
         ret->left = r;
         return ret;
    }
};
