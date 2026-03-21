/*
6. Z 字形变换

将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len=s.size();
        // 亚索矩阵方法
        vector<string> eachrow(numRows);
        string sum = "";
        int go=-1;

        if(numRows==1||len<numRows) return s;
        
        for(int i = 0,now_row = 0;i<len;i++){
            eachrow[now_row] += s[i];
            if(now_row==numRows-1 || now_row==0){
                go = -go;
            }
            now_row+=go;
        }

        for(int i=0;i<numRows;i++){
            sum+= eachrow[i];
        }

        return sum;
    }
};