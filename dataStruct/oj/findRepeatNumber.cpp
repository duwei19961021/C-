/*
 * 数组中重复的数字
 * 链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 */

/*
class Solution {
public:
    int findRepeatNumber(vector<int>& nums)
    {
        int ret = 0;
        ::sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                ret = nums[i];
                break;
            }
        }
        return ret;
    }
};
*/

/*
class Solution {
public:
    int findRepeatNumber(vector<int>& nums)
    {
        int ret = 0;
        map<int,int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            auto result = m.insert(pair<int,int>(nums[i],-1));
            if(result.second == false)
            {
                ret = nums[i];
                break;
            }
        }
        return ret;
    }
};
*/

class Solution {
public:
    int findRepeatNumber(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i] != i)
            {
                if(nums[i] == nums[nums[i]])
                {
                    return nums[i];
                }
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return -1;
    }
};
