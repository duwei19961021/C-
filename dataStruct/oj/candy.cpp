/*
 * 分发糖果
 * 链接：https://leetcode-cn.com/problems/candy/
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> ret(ratings.size(),1); // 每个学生都先发一颗糖
        for(int i = 1; i < ratings.size(); i++)
        {
            if(ratings[i] > ratings[i-1]) // 如果当前学生评分比前一个高,那么当前学生的糖果应该比前一个学生的糖果多一个。（左->右）
            {
                ret[i] = ret[i-1]+1;
            }
        }
        for(int i = ratings.size()-1; i > 0; i--) // 如果当前学生的评分比前一个学生低，那么前一个学生的糖果应该比当前学生多。（右->左）
        {
            if(ratings[i-1] > ratings[i])
            {
                ret[i-1] = max(ret[i-1],ret[i]+1);
            }
        }
        return accumulate(ret.begin(),ret.end(),0);
    }
};

/*
[1,0,2]
 1 1 1
 1 1 2
 2 1 2
 */
