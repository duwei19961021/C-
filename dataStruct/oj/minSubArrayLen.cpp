/* 长度最小的子数组
 * 链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 */

/*
// 暴力法: O(N^2)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        vector<vector<int>> ret;
        for(int i = 0; i < nums.size(); i++)
        {
            vector<int> tmp;
            int tmpSum = 0;
            for(int j = i; j < nums.size();j++)
            {
                tmpSum += nums[j];
                tmp.push_back(nums[j]);
                if(tmpSum >= target)
                {
                    ret.push_back(tmp);
                    break;
                }
            }
        }
        if(ret.size() == 0)
        {
            return 0;
        }
        int min = ret[0].size();
        for(int i = 0; i < ret.size();i++)
        {
            if(ret[i].size() < min)
            {
                min = ret[i].size();
            }
        }
        return min;
    }
};
*/

// 滑动窗口: O(N)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int fastIndex = 0, slowIndex = 0;
        int min = nums.size();
        int sum = 0;
        int flag = 0;
        while(fastIndex < nums.size())
        {
            sum += nums[fastIndex];
           while(sum >= target) // 如果sum大于target则要收缩窗口的起始位置(sum减去窗口起始位置的值且起始位置往后移动一位)
           {
               flag = 1; // 如果flag没有被赋值则说明sum从来没有大于过target
               int length = fastIndex - slowIndex + 1;
               if(length < min) // 保持最小窗口的长度
               {
                   min = length;
               }
               sum -= nums[slowIndex];
               slowIndex++;
           }
           fastIndex++;
        }
        
        if(flag == 0)
        {
            return 0;
        }
        return min;
    }
};
