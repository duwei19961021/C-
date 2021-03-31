/*
 * 最大子序和
 * 链接：https://leetcode-cn.com/problems/maximum-subarray/
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int res = nums[0];
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(sum + nums[i] > nums[i])
            {
                /*
                    说明当前 nums[i] 之前的数的和是正的(此题没有限制子数组的长度，只要是正就可以往后加)，
                */
                sum = sum + nums[i];
            }
            else
            {
                /* 
                    如果sum 加上 nums[i] 还比 nums[i]小说明这之前的数的和是负数，
                    因此可以舍弃掉，直接让sum等于当前这个数重新开始计算。
                */
                sum = nums[i];
            }
            res = res > sum ? res:sum; // 保存求和过程中出现的最大值
        }
        return res;
    }
};
