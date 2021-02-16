/*
 * 两数之和
 * 链接：https://leetcode-cn.com/problems/two-sum/submissions/
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ret;
        map<int,int> numsMap; // 利用hashTable的高查找效率
        for(int i = 0; i < nums.size(); i++)
        {
            auto it = numsMap.find(target-nums[i]); // 先查找target-nums[i]是否存在于map中
            if(it == numsMap.end()) // 不存在则插入,这样可以避免自己和自己匹配（[3,3],返回[0,0]这种情况,如果先插入再查找,插入下标0的3之后,再搜索map则会找到自己本身）
            {
                numsMap[nums[i]] = i; // 插入数在nums中的索引作为map的值
            }
            else // 存在则说明i和numsMap[target-nums[i]]是要找的数的下标
            {
                ret.push_back(i);
                ret.push_back(numsMap[target-nums[i]]);
            }
        }
        return ret;
    }
};
