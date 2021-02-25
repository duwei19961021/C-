/*
 * 分发饼干
 * 链接：https://leetcode-cn.com/problems/assign-cookies/
 */

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        size_t gIndex = 0;
        size_t sIndex = 0;
        while(gIndex < g.size() && sIndex < s.size())
        {
            if(s[sIndex] >= g[gIndex]) // 能满足则发下一块饼干给下一个孩子
            {
                gIndex++;
                sIndex++;
            }
            else
            {
                sIndex++; // 不能满足则尝试后一块饼干是否能满足孩子胃口
            }
        }
        return gIndex;
    }
};
