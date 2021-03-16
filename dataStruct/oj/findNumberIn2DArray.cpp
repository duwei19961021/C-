/*
 *  二维数组中的查找
 *  链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 */

class Solution {
public:
    bool BinarySearch(vector<int>& v, int target)
    {
        if(target > v.back()) // 内部的多个数组都是有序的，如果内部数组的最后一个元素小于target，则可以直接判定这个数组中不存在target
        {
            return false;
        }

        int start = 0, end = v.size()-1,mid;
        
        while(start <= end)
        {
            mid = (start+end)/2;
            if(v[mid] == target)
            {
                return true;
            }
            if(v[mid] > target)
            {
                end = mid -1;
            }
            if(v[mid] < target)
            {
                start = mid+1;
            }
        }
        return false;
    }

    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target)
    {
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }
        int col_start = 0, col_end = matrix.size()-1, col_mid;
        while(col_start <= col_end)
        {
            col_mid = (col_start + col_end)/2;
            if(matrix[col_mid][0] == target)
            {
                return true;
            }
            if(matrix[col_mid][0] > target)
            {
                col_end = col_mid - 1;
            }
            if(matrix[col_mid][0] < target)
            {
                col_start = col_mid + 1;
            }
            if(col_mid+1 < matrix.size() && matrix[col_mid+1][0] > target && matrix[col_mid][0] < target) // 第mid个数组的第一个元素小于target，mid下一个数组的第一个元素大于target则说明找到了分界点
            {
                break;
            }
        }
        for(int i = 0; i <= col_mid; i++)
        {
            if(BinarySearch(matrix[i],target))
            {
                return true;
            }
        }
        return false;
    }
};
