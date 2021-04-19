/*
 * 数组中出现次数超过一半的数字
 * 链接：https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int ret = 0;
        map<int, int> m;
        for(size_t i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        for(size_t i = 0; i < nums.size(); i++)
        {
            if(m[nums[i]] > nums.size() / 2)
            {
                ret = i;
                break;
            }
        }

        return nums[ret];
    }
};
