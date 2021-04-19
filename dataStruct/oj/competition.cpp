/*
 * 组队竞赛
 * 链接：https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> ret;

    int n;
    cin >> n;
    int num;

    while(cin >> num)
    {
        ret.push_back(num);

        if(cin.get() == '\n')
        {
            break;
        }
    }

    sort(ret.begin(),ret.end());

     long long  sum = 0;

    for(int i = n;i<= 3*n -2;i+=2)
    {
        sum += ret[i];
    }

    cout << sum << endl;
    return 0;
}

/*
 * 解题思路：贪心
 *
 * 2
 * 5 2 8 5 1 5
 * 进行排序：1 2 5 5 5 8
 * 排序之后右边是大数，第一次：组合8 5 1 为一组，第二次组合：5 5 2 一组
 */
