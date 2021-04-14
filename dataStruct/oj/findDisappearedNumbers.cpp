/*
 * 448. 找到所有数组中消失的数字
 * 链接：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        if(nums.empty())
        {
            return nums;
        }
        vector<int> ret;
        int n = nums.size();
        for(size_t i = 0; i < n; i++)
        {
            size_t index = (nums[i] - 1) % n;
            nums[index] += n;
        }

        for(size_t i = 0; i < n; i++)
        {
            if(nums[i] <= n)
            {
                ret.push_back(i+1);
            }
        }
        return ret;
    }
};
