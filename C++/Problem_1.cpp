#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // for(int i = 0; i<nums.size(); i++){
            
        //     for(int j = i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j] == target){
        //             return {i,j};
        //         }
        //     }
        // }

        // return {};



        // hashtable:
        unordered_map<int,int> hashtable;

        for(int i=0;i<nums.size();i++){
            auto it = hashtable.find(target-nums[i]);
            if(!(it == hashtable.end())){
                return {it->second,i};
            }
            hashtable[nums[i]] = i;
        } 
        return {};
    }
};