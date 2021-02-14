/*
 * 仅仅反转字母
 * 链接：https://leetcode-cn.com/problems/reverse-only-letters
 */
class Solution {
public:
    string reverseOnlyLetters(string S) {
        string newS(S);
        int start = 0;
        int end = S.length();
        while(start < end)
        {
            while(start <  end && !((newS[start] >= 'a' && newS[start] <= 'z') || (newS[start] >= 'A' && newS[start] <= 'Z')))
            {
                start++;
            }
            while(start <  end && !((newS[end] >= 'a' && newS[end] <= 'z') || (newS[end] >= 'A' && newS[end] <= 'Z')))
            {
                end--;
            }
            char temp = newS[start];
            newS[start] = newS[end];
            newS[end] = temp;
            start++;
            end--;
        }
        return newS;
    }
};
