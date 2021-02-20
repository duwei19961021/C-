/*
 * 逆波兰表达式求值
 * 链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 */

class Solution {
public:
    int str2int(string s) // 字符转int
    {
        int end = 0;
        int flag = 1;
        int next = 1;
        int ret = 0;
        if(s[0] == '-')
        {
            flag = -1;
            end = 1;
        }
        for(int i = s.size()-1; i >= end; i--)
        {
            ret += (s[i]-'0')*next;
            next *= 10;
        }
        return  ret*flag;
    }

    int cal(int num1, int num2, string op) // 根据符号计算结果
    {
        if(op[0] == '+')
            return num2+num1;
        else if(op[0] == '-')
            return num2-num1;
        else if(op[0] == '*')
            return num2*num1;
        else if(op[0] == '/')
            return num2/num1;
        return 0;
    }

    int evalRPN(vector<string>& tokens)
    {
        stack<string> s;
        int ret =  0;
        for(size_t i = 0; i < tokens.size(); i++)
        {
            if(tokens[i][0]=='+' || (tokens[i][0]=='-' && tokens[i].size() == 1) || tokens[i][0]=='*' || tokens[i][0]=='/') // 是运算符则从栈中取出连续的两个数进行计算(注意负数的判断)
            {
                int num1 = str2int(s.top());
                s.pop();
                int num2 = str2int(s.top());
                s.pop();
                ret = cal(num1,num2,tokens[i]);
                s.push(to_string(ret));
            }
            else // 不是运算符则是数字,压入栈中
            {
                string tmp(tokens[i]);
                s.push(tmp);
            }
        }
        int result = 0;
        while(!s.empty()) // 取出栈中的结果
        {
            result += str2int(s.top());
            s.pop();
        }
        return result;
    }
};
