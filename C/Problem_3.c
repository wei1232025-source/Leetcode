/*
3. 无重复字符的最长子串
给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
*/

// 哈希表的思路

int lengthOfLongestSubstring(char* s) {
    int arr[128] = {0};
    int max = 0, cnt = 0, left = 0;

    for(int i=0 ; s[i]!='\0';i++){
        if(arr[s[i]] == 0){
            arr[s[i]] = 1;
            cnt ++;
            if(cnt>max){
                max = cnt;
        }
        }else {
            arr[s[left++]] = 0;
            cnt --;
            i --;
        }



    }
    return max;
}