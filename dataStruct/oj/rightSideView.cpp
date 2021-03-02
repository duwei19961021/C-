/**
 * 二叉树的右视图
 * 链接：https://leetcode-cn.com/problems/binary-tree-right-side-view/
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

/*
// 层序遍历，最后一个元素就是要保存的值

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vector<int> ret;
        if(root == nullptr)
        {
            return ret;
        }
        q.push(root);
        while(!q.empty())
        {
            ret.push_back(q.back()->val);
            for(int i = q.size(); i > 0; i--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ret;
    }
};
*/

// dfs
// 根结点 -> 右结点 -> 左结点,保证在访问每一层时都是先访问右子树，且一层只能push一个元素进入ret(层高从0开始计算)
class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ret, int Depth)
    {
        if(root == nullptr)
        {
            return;
        }
        if(Depth == ret.size())
        {
            ret.push_back(root->val);
        }
        Depth++;
        dfs(root->right,ret,Depth); // 从根结点开始遍历右子树，遍历一个元素push进ret一个元素，遍历到右子树的结束后回溯到左子树继续递归右子树，ret中的元素应该和遍历的层数相等，比如说从根结点开始的所有右子树遍历完之后再遍历左子树，如果ret中的元素个数不等于当前结点的层高则说明此层已经push过元素进入ret了(也就是此节点右边有元素存在，当前元素会被遮挡)
        dfs(root->left,ret,Depth);
    }

    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ret;
        dfs(root,ret,0);
        return ret;
    }
};

