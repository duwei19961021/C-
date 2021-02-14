/*
 * 验证回文串
 * 链接：https://leetcode-cn.com/problems/valid-palindrome/submissions/
 */

class Solution {
public:
    bool isLetter(char c) // 判断是否是字母和数字
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        for(auto &ch:s) // 先将大写转小写
        {
            if(ch >= 'A' && ch <= 'Z')
            {
                ch += 32;
            }
        }
        int start = 0, end = s.size()-1; // 双指针：start指向第一个字符，end指向最后一个字符
        while(start < end)
        {
            while(start < end && !isLetter(s[start])) // 走到是字母或者数字的位置停止
            {
                start++;
            }
            while(start < end && !isLetter(s[end])) // 走到是字母或者数字的位置停止
            {
                end--;
            }
            if(s[start] != s[end]) // 判断是否相等
            {
                return false;
            }
            start++; // 判断完要继续向中间位置靠拢
            end--;
        }
        return true;
    }
};
