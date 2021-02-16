/*
 * 二进制求和
 * 链接：https://leetcode-cn.com/problems/add-binary/
 */

class Solution {
public:
    string addBinary(string a, string b) 
    {
        int endA = a.size()-1, endB = b.size()-1;
        string retStr;
        int next = 0;
        while(endA >= 0 || endB >= 0)
        {
            int valA = 0;
            int valB = 0;
            if(endA >= 0)
            {
                valA = a[endA] - '0';
            }
            if(endB >= 0)
            {
                valB = b[endB] - '0';
            }
            int ret = valA + valB + next;
            if(ret > 1)
            {
                ret -= 2;
                next = 1;
            }
            else
            {
                next = 0;
            }
            retStr.insert(retStr.begin(),ret+'0');
            endA--;
            endB--;
        }
        if(next == 1)
        {
            retStr.insert(retStr.begin(),'1');
        }
        return retStr;
    }
};
