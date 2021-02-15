/*
 * 加一
 * 链接：https://leetcode-cn.com/problems/plus-one/
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        vector<int> retV;
        int next = 1;
        int end = digits.size()-1;
        while(end >= 0)
        {
            int ret = digits[end]  + next;
            if(ret > 9)
            {
                ret -= 10;
                next = 1;
            }
            else
            {
                next = 0;
            }
            retV.insert(retV.begin(),ret);
            end--;
        }
        if(next == 1)
        {
            retV.insert(retV.begin(),next);
        }
        return retV;
    }
};
