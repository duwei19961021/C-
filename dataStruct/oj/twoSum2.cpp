/**
 * 两数之和 II - 输入有序数组
 * 链接：https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
 */

// 有序序列一定要想到二分查找
// O(n*logn)

class Solution {
public:
    int BinatySearch(vector<int>& numbers, int num, int start)
    {
        int left = start, right = numbers.size()-1;
        int mid = 0;
        while(left <= right)
        {
            mid = (left+right)/2;
            if(num == numbers[mid])
            {
                return mid;
            }
            if(num > numbers[mid])
            {
                left = mid+1;
            }
            if(num < numbers[mid])
            {
                right = mid-1;
            }
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        for(int i = 0; i < numbers.size(); i++)
        {
            int index = BinatySearch(numbers,target-numbers[i],i+1);
            if(index != -1)
            {
                ret.push_back(i+1);
                ret.push_back(index+1);
                break;
            }
        }
        return ret;
    }
};
