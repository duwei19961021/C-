/*
 * 数组中的逆序对
 * 链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
 */

class Solution {
public:
    void _merageSort(vector<int>& v, int left, int right, vector<int>& help, int& ret)
    {
        if(left >= right)
        {
            return;
        }
        int mid = (left+right)/2;
        _merageSort(v, left, mid, help, ret);
        _merageSort(v, mid+1, right, help, ret);
        int begin1 = left, end1 = mid;
        int begin2 = mid+1, end2 = right;
        int index = begin1;

        while(begin1 <= end1 && begin2 <= end2)
        {
            if(v[begin1] <= v[begin2])
            {
                help[index++] = v[begin1++];
            }
            else
            {
                help[index++] = v[begin2++];
                ret += end1 - begin1 + 1;
            }
        }

        while(begin1 <= end1)
        {
            help[index++] = v[begin1++];
        }

        while(begin2 <= end2)
        {
            help[index++] = v[begin2++];
        }

        for(int i = left; i <= right; i++)
        {
            v[i] = help[i];
        }
    }

    void merageSort(vector<int>& v, int& ret)
    {
	    vector<int> help(v.size(),v.size());
	    _merageSort(v, 0, v.size()-1, help, ret);
    }

    int reversePairs(vector<int>& nums)
    {
        int ret = 0;
        merageSort(nums, ret);
        return ret;
    }
};
