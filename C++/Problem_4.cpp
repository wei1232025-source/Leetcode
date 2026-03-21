/*
4. 寻找两个正序数组的中位数

给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

 
*/



#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> nums3(len1+len2);
        int i =0, j = 0, k = 0;
        while(i<len1 && j<len2){
            if(nums1[i]<=nums2[j]){
                nums3[k++] = nums1[i++];
            }else{
                nums3[k++] = nums2[j++];
            }
        }
        while(i<len1){
            nums3[k++] = nums1[i++];
        }
        while(j<len2){
            nums3[k++] = nums2[j++];
        }

        if((len1+len2)%2){
            return nums3[k/2];
        }else {
            // 注意结果为实数要求 '/' 两边有实数
            return (nums3[(k-1)/2]+nums3[(k+1)/2])/2.0;
        }
    }
};