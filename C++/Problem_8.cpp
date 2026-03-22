/*
8. 字符串转换整数 (atoi)

请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数。

函数 myAtoi(string s) 的算法如下：

1. 空格：读入字符串并丢弃无用的前导空格（" "）
2. 符号：检查下一个字符（假设还未到字符末尾）为 '-' 还是 '+'。如果两者都不存在，则假定结果为正。
3. 转换：通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。
4. 舍入：如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被舍入为 −231 ，大于 231 − 1 的整数应该被舍入为 231 − 1 。
返回整数作为最终结果。


*/

#include <iostream>


using namespace std;

// 我的解答，感觉过于冗余

class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        int sum = 0;
        long cns = 0;
        int flag = 0;
        int sign = 1;

        for(int i = 0;i<len;i++){

            if(isdigit(s[i])){
                flag = 1;
                int carry = s[i]-'0';
                cns = 10*cns + carry;
                if(cns>INT_MAX && sign ==1 )   return INT_MAX;
                else if(-cns<INT_MIN && sign == -1) return INT_MIN;
            }else if(s[i]=='-' && flag == 0 && isdigit(s[i+1])) {
                sign = -1;
            }else if(s[i] == '+' && flag==0 && isdigit(s[i+1])){
                sign = 1;
            }else if(flag == 1){
                break;
            }else if(!isspace(s[i])){
                break;
            }

        }

        cns = cns*sign;
        if(cns<INT_MIN) return INT_MIN;
        else if(cns>INT_MAX) return INT_MAX;

        sum = cns;
        return sum;
        
        
    }
};