/*
 * 剑指 Offer 31. 栈的压入、弹出序列
 * 链接：https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
 */

/*
 * 创建一个栈尝试入栈，入栈时如果堆顶元素与popped的元素相同则出栈
 * 如果最后pushed的索引走到了对应的vector末尾且栈空则是可以的
 */

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        size_t j = 0;
        for(size_t i = 0; i < pushed.size(); i++)
        {
            s.push(pushed[i]);
            while(!s.empty() && j < popped.size() && s.top() == popped[j])
            {
                s.pop();
                ++j;
            }
        }
        return j == popped.size() && s.empty();
    }
};
