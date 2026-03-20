#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len=s.size();
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