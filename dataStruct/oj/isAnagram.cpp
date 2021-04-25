/*
 * 有效的字母异位词
 * 链接：https://leetcode-cn.com/problems/valid-anagram/
 */

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        map<char, int> m1; // s

        map<char, int> m2; // t

        size_t i;

        if(s.size() != t.size())
        {
            return false;
        }

        for(i = 0; i < s.size(); i++)
        {
            m1[s[i]]++;
            m2[t[i]]++;
        }

        for(i = 0; i < t.size(); i++)
        {
            if(m2[t[i]] != m1[t[i]])
            {
                return false;
            }
        }

        return true;
    }
};
