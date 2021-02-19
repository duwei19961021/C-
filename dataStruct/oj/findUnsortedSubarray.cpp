/*
 * 最短无序连续子数组
 * 链接：https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int length = nums.size();
        int min = nums[length-1];
        int max = nums[0]; // 数组中最小的值
        int begin = 0,end = 0;
        for(size_t i = 0; i < length; i++)
        {
            if(nums[i] < max)
                end = i;
            else
                max = nums[i];

            if(nums[length-i-1] > min)
                begin = length - i - 1;
            else
                min = nums[length -i - 1];
        }
        if(begin ==0 && end == 0)
            return 0;
        else
            return end - begin + 1;
    }
};

/*
 * 数组可分为三段：左有序段、中无序段、右有序段
 * 无序段中的最小值一定比左有序段中的最大值大
 * 无序段中的最大值一定比右有序段中的最小值小
 */
