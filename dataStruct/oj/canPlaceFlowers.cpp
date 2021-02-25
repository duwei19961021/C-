/*
 * 种花问题
 * 链接：https://leetcode-cn.com/problems/can-place-flowers/
 */

// 贪心

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int count = 0;
        for(int i = 0; i < flowerbed.size();i++)
        {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && ( i  == flowerbed.size() - 1 ||flowerbed[i+1] == 0)) // 能种花的条件：当前位置为0(没种花) && 当前位置的前一个位置为0 && 当前位置的后一个位置为0，然后有两个特殊位置需要处理：当i为0时没有前一个位置，当i为最后一个位置时没有后一个位置。
            {
                flowerbed[i] = 1;
                count++;
                i++;
            }
        }
        return count>=n;
    }
};
