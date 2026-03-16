/*
1. 两数之和

  给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
你可以按任意顺序返回答案。


*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10


int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main(void){
    int Rsize = 0;
    int numbers[10] = {1,2,3,4,5,6,7,8,9,10};
    int target = 0;
    scanf("%d",&target);
     
    int *Return;
    Return = twoSum(numbers,SIZE,target,&Rsize);

    for(int i=0;i<Rsize;i++){
        printf("%d ",Return[i]);
    }

    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ret = malloc(2*sizeof(int));
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                ret[0]=i;
                ret[1]=j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
