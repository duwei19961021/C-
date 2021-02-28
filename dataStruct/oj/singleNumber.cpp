/* *
 * 只出现一次的数
 * 链接：https://leetcode-cn.com/problems/single-number/submissions/
 */

// 两个相同的数异或为0，任何数与0异或为自己，异或支持交换律
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ret = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ret ^= nums[i];
        }
        return ret;
    }
};
