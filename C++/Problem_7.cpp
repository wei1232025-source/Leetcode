#include<iostream>
#include<vector>

using namespace std;

/*
7. 整数反转
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）

*/

// class Solution {
// public:
//     int reverse(int x) {
//         long s = fabs(x);
//         long rev = 0;

//     while(s!=0){
//         rev = 10*rev + s%10;
//         s/=10;
//         if(rev>= pow(2,31)) return 0;
//     }

//     if(x>=0) return rev;
//     else return -rev;

        
//     }
// };
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int k = x;
        
        while(x!=0){
            int pop = x%10;
            if((rev<INT_MIN/10)||(rev>INT_MAX/10)){
                return 0;
            }
            if((rev == INT_MIN/10&&pop<-8)||(rev == INT_MAX/10&&pop>7)){
                return 0;
            }
            rev = 10*rev+pop;
            x /= 10;
        }

        return rev;
        
    }
};
