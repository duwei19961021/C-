/*
 * 字符串中的第一个唯一字符
 * 链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string
 */

class Solution {
public:
    int firstUniqChar(string s) {
        int letter[26] = {0};
        
        for(int i = 0; i < s.length(); i++)
        {
            letter[s[i]-'a']++;
        }

        for(int i = 0; i < s.length(); i++)
        {
            if(letter[s[i]-'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
