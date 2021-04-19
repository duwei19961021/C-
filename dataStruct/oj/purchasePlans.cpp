/*
 * 采购方案
 * 链接：https://leetcode-cn.com/problems/4xy4Wx/
 */

class Solution {
public:
    int purchasePlans(vector<int>& nums, int target)
    {
        long long ret = 0;
        sort(nums.begin(),nums.end());
        size_t start  = 0, end = nums.size()-1;
        while(start < end)
        {
            if(nums[start] + nums[end] <= target)
            {
                ret += end - start;
                start++;
            }
            else
            {
                end--;
            }
        }
        return ret%1000000007;
    }
};

/*
 * 2 2 1 9
 * 双指针解法：
 * 先排序 => 1 2 2 9
 * nums[0] + nums[3] <= 10 成立，则 nums[0] + nums[1] ~ nums[3] 之间的数都成立，即 1+2、1+2、1+9
 */
