#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> hashtable;
        int len = s.size();
        int left=0;
        int cnt=0;
        int max=0;
        for(int i=0;i<len;i++){
            auto it = hashtable.find(s[i]);
            if(!(it==hashtable.end())&&it->second == 1){
                    hashtable[s[left++]] = 0;
                    i--;
                    cnt--;
            }else{
                hashtable[s[i]] = 1;
                cnt++;
                if(cnt>=max) max = cnt;
            }
        }

        return max;
    }
};