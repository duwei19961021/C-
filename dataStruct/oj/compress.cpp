/*
 * 压缩字符串
 * 链接：https://leetcode-cn.com/problems/string-compression/
 */

class Solution {
public:
    int GetLength(int nums) // 获取字母计数的结果的值的长度(几位数)
    {
        size_t lenth = 0;
        while(nums > 0)
        {
            nums /= 10;
            lenth++;
        }
        return lenth;
    }

    int compress(vector<char>& chars) 
    {
        if(chars.size() <= 1) // chars的长度小于等于1则说明只有一个字符
        {
            return 1;
        }
        size_t first = 0;
        size_t second = 0;
        while(second < chars.size()) //遍历数组的边界
        {
            size_t count = 0;
            while(second < chars.size() && chars[first] == chars[second]) // second < chars.size() 不可少,否则数组会发生越界访问
            {
                count++;
                second++;
            }
            if(count < 2) // count 小于2 也就是一个字母的情况不在数组中记录个数
            {
                first++; // 直接进入下一个字母
            }
            else if(count >= 2 && count < 10) // 大于1小于10的情况,字母个数直接写在fist的下一个位置上
            {
                chars[first+1] = (count+'0');
                first += 2;
                if(second < chars.size() &&  first < chars.size()) // [a,a] 避免second和first的下一个位置越界 
                {
                    chars[first] = chars[second];
                }
            } 
            else if(count >= 10) // 个数是两位或者两位以上的情况，需要占用多个位置
            {
                size_t length = GetLength(count);
                size_t sto_length = length;
                while(length > 0)
                {
                    size_t num = (count % 10);
                    count /= 10;
                    cout << "count = "<< count << endl;
                    chars[first+length] = num+'0';
                    length--;
                }
                first += sto_length+1; 
            }
            if(second < chars.size()) // 如果second还没走到末尾就说明后面还有字母需要计数
            {
                chars[first] = chars[second]; // 此时fisrt指向计数数字在数组中位置的下一个位置，将此位置置为second位置的值
            }
            
        }
        return first;
    }
};
