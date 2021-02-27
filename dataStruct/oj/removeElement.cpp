/*
 * 移除元素
 * 链接：https://leetcode-cn.com/problems/remove-element/
 */

/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        for(auto it = nums.begin(); it != nums.end(); it++)
        {
            if(*it == val)
            {
                nums.erase(it);
                it--;
            }
        }
        return nums.size();
    }
};
*/

// O(N)
class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int slowIndex = 0;
        int fastIndex = 0;
        while(fastIndex < nums.size())
        {
            if(nums[fastIndex] != val) // 如果遇上等于val的位置fast会先走(slow停止)，直到fast再次遇见不等于val的位置，将此时fast的指向值赋值给slow
            {
                nums[slowIndex] = nums[fastIndex];
                fastIndex++;
                slowIndex++;
            }
            else
            {
                fastIndex++;
            }
        }
        return slowIndex;
    }
};
