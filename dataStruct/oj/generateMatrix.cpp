/*
 * 螺旋矩阵 II
 * 链接：https://leetcode-cn.com/problems/spiral-matrix-ii/
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int num = 1, j = 0;
        while(num <= n*n)
        {
            for(int i = j; i < n-j; i++) // 左->右
            {
                ret[j][i] = num++;
            }

            for(int i = j+1; i < n-j; i++) // 上->下
            {
                ret[i][n-j-1] = num++;
            }

            for(int i = n-j-1-1; i >= j;i--) // 右->左
            {
                ret[n-j-1][i] = num++;
            }

            for(int i = n-j-1-1;i > j;i--) // 下->上
            {
                ret[i][j] = num++;
            }
            j++; // 循环完一圈
        }
        return ret;
    }
};
