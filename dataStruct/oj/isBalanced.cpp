/**/

class Solution {
public:
    bool _isBalanced(TreeNode* root,int& Depth)
    {
        if(root == nullptr) // 从最底层开始计算高度
        {
            Depth = 0; // 通过Depth将高度告诉上一层
            return true;
        }
        else
        {
            int leftDepth = 0;
            if(_isBalanced(root->left,leftDepth) == false) // 会递归到空借点，然后开始返回开始递归右结点。先从左子树的最后一个位置开始遍历
            {
                return false;
            }
            int rightDepth = 0;
            if(_isBalanced(root->right,rightDepth) == false) // 左子树遍历完返回上一层遍历右子树
            {
                return false;
            }
            if(abs(leftDepth - rightDepth) > 1) // 高度差大于1则可以直接返回了
            {
                return false;
            }
            else
            {
                Depth = leftDepth > rightDepth ? leftDepth+1:rightDepth+1; // 如果这颗子树是平衡树,则将此子树的高度+1传给上一层(此层高度+1就是上一层的高度)
            }
        }
        return true;
    }

    bool isBalanced(TreeNode* root) 
    {
        int Depth = 0;
        return _isBalanced(root, Depth);
    }
};
