/**
 * 树的子结构
 * 链接：https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof
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
    bool _isSubStructure(TreeNode* _A, TreeNode* _B) // 前序遍历
    {
        if(_B == nullptr) // 2、1中已经判断过B不为空,能进入这个条件说明已经至少递归过一次了,如果B为空说明B走到空之前的路径 A也具有与B相同的路径且值相等，所以满足是子结构
        {
            return true;
        }
		
		// 对于B的判断一定要先于A

        if(_A == nullptr) // 3、如果B不为空A却为空了说明B还没遍历完成A就结束了则必不可能满足子结构
        {
            return false;
        }

        if(_A->val != _B->val) // 4、值不同不满足
        {
            return false;
        }
        
        return _isSubStructure(_A->left,_B->left) && _isSubStructure(_A->right,_B->right); // 递归左右子树,这里必须是 && ，左右子树同时满足子结构，B才是A的子结构
    }

    bool isSubStructure(TreeNode* A, TreeNode* B)
    {
        if(B == nullptr || A == nullptr) // 1、首先判断A B,如果有一个为空则子结构必然不成立
        {
            return false;
        }
        return  _isSubStructure(A,B) || isSubStructure(A->left, B) || isSubStructure(A->right,B); // 先找根结点相同的位置，再左右递归
    }
};
