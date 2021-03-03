/**
 * 存在连续三个奇数的数组
 * 链接：https://leetcode-cn.com/problems/three-consecutive-odds/
 */

// 滑动窗口
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr)
    {
        int size = arr.size();
        int begin = 0;
        int end = 0;
        while(begin < size)
        {
            if(end < size && arr[end] % 2 == 1)
            {
                end++;
            }
            else
            {
                begin = end+1;
                end++;
            }

            if(end-begin == 3)
            {
                return true;
            }
        }
        return false;
    }
};
