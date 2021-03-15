/*
 * 0～n-1中缺失的数字
 * 链接：https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int left = 0, right = nums.size()-1, mid = 0;
        while(left <= right)
        {
            mid = (left+right)/2;
            if(nums[mid] == mid)
            {
                left = mid + 1;
            }
            if(nums[mid] > mid)
            {
                right = mid-1;
            }
        }

        if(mid == right) // 说明没有缺则返回最后一个数+1
        {
            return mid+1;
        }
        return mid;
    }
};
