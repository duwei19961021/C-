/*
 * 两个数组的交集
 * 链接：https://leetcode-cn.com/problems/intersection-of-two-arrays/
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int,int> m1;
        map<int,int> m2;
        vector<int> ret;
        size_t i = 0;
        size_t j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            m1[nums1[i]]++;
            i++;
            m2[nums2[j]]++;
            j++;
        }

        while(i < nums1.size())
        {
            m1[nums1[i]]++;
            i++;
        }

        while(j < nums2.size())
        {
            m2[nums2[j]]++;
            j++;
        }

        for(auto it = m1.begin(); it != m1.end(); it++)
        {
            if(m2[it->first] >= 1)
            {
                ret.push_back(it->first);
            }
        }
        
        return ret;
    }
};
