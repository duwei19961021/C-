/*
 * 剑指 Offer 56 - I. 数组中数字出现的次数
 * 链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
 */

/*
 * 解题思路：
 * 			相同的两个数异或等于0，任何数与0异或等于自己本身
 * 			数组中只有两个数字只出现一次，其它数都出现两次，那么其它数进行异或之后结果为0，剩下的两个出现一次的数异或即为数组中所有元素异或的结果
 * 			由于采用的是异或，所以得到的异或结果，从低比特位到高比特位，为1的位上表示两个单独出现数字的对应比特位不同，可以根据这个将数组的数字分组，
 * 			然后对各自分组进行异或得到两个结果，就是只出现一次的数字
 */

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) 
    {
        vector<int> ret;
        uint32_t tmp = 0,flag = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            tmp ^= nums[i];
        }

        for(int i = 0; i < 32; i++)
        {
            if(((tmp >> i) & 1) == 1)
            {
                flag = i;
                break;
            }
        }

        int num1 = 0, num2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(((nums[i] >> flag) & 1) == 0)
            {
                num1 ^= nums[i];
            }

            if(((nums[i] >> flag) & 1) == 1)
            {
                num2 ^= nums[i];
            }
        }

        ret.push_back(num1);
        ret.push_back(num2);
        return ret;
    }
};
