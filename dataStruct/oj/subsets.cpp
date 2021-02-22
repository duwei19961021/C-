/*
 * 子集
 * 链接：https://leetcode-cn.com/problems/subsets/
 */

class Solution {
public:
    void dfs(int step, vector<int>& nums, vector<vector<int>>& result, vector<int> temp)
    {
        if(step == nums.size()) // 退出条件
        {
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[step]); // push 第一个元素进入temp
        dfs(step+1,nums,result,temp); // 紧接着push第二个元素..... 一直递归下去,直到每个元素都push进temp,此时temp里的元素等于nums的元素(一个集合的本身也是一个子集),达到递归的退出条件开始返回(返回时temp会被push进result)。
        temp.pop_back(); // 弹出temp的最后一个元素(子集减去一个元素也还是子集,此时temp中保存的是比本身少一个元素的子集)
        dfs(step+1,nums,result,temp); // 此时step+1==nums.size(),达到退出条件,temp再次push进result(但是元素已经被pop掉一个)
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(0,nums,result,temp);
        return result;
    }
};

/*
 * 解题思路：一条路走到黑
 */
