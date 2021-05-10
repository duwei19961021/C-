/*
 * 快乐数
 * 链接：https://leetcode-cn.com/problems/happy-number/
 */

class Solution {
public:
    map<int, int> m;

    int getHappyNum(int n)
    {
        int ret = 0;

        while(n)
        {
            ret += (n%10) * (n%10);
            n /= 10;
        }

        return ret;
    }

    bool isHappy(int n) 
    {
        while(1)
        {
            int sum = getHappyNum(n);
            if(sum == 1) // 结果为1则为快乐数
            {
                return true;
            }

            m[sum]++; // 不为1，则将sum进行计数

            if(m[sum] > 1) // 如果一个结果在map中出现一次以上，说明结果快乐数计算过程中出现了重复结果，则必定会死循环
            {
                return false;
            }

            n = sum; // 继续计算sum，直到为1或者出现重复
        }
    }
};
