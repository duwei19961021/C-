/*
 * 删除有序数组中的重复项
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size() == 0)
        {
            return 0;
        }
        else if(nums.size() == 1)
        {
            return 1;
        }
        size_t first = 0, second = 1;
        while(second < nums.size())
        {
            if(nums[second] != nums[first])
            {
                nums[++first] = nums[second];
            }
            second++;
        }
        return first+1;
    }
};
