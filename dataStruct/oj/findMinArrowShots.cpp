/*
 * 用最少数量的箭引爆气球
 * 链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
 */

class Solution {
public:
    static bool MySort(vector<int>& v1, vector<int>& v2)
    {
        return v1[1] < v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points)
    {
        int ret = 0;
        if(points.size() == 0)
        {
            return ret;
        }
        sort(points.begin(),points.end(),MySort); // 以右边界排序
        int  size = 0;
        int tmp = 1;
        while(tmp < points.size())
        {
            if(points[tmp][0] <= points[size][1]) // 在第一个气球的区间范围内气球是绝对能被引爆的，所以直接从第二个气球开始遍历，如果遍历指向的当前气球的左边界小于第一个气球的右边界则说明它们的区间存在重合(存在重合则可以被一只箭一次射爆)，然后继续判断下一个气球的区间是否与第一个气球的区间是否重合......
            {
                tmp++;
            }
            else // 如果判断到不重合的，ret计数加1，然后将size指向tmp位置继续下一轮判断
            {
                ret++;
                size = tmp;
            }
        }
        return ret+1; // 由于tmp遍历到最一个气球之后循环不会再进入，所以要加上最后一箭
    }
};
