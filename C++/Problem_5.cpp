/*
5. 最长回文子串
给你一个字符串 s，找到 s 中最长的 回文 子串。


*/

// 动态规划
#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int l = 1;
        int maxlen =1;
        int point = 0;
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i =0;i<n;i++){
            dp[i][i] = 1;
        }

        for(l=2;l<=n;l++){
            for(int i =0;i<n;i++){
                int j = l+i-1;
                if(j>=n) break;
                if(s[i]!=s[j]){
                    dp[i][j] = 0;
                }else{
                    if(l==2){
                        dp[i][j]=1;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }

                if(dp[i][j] && l>maxlen){
                    maxlen = l;
                    point = i;
                }
            }
        }

        return s.substr(point,maxlen);
    }
};