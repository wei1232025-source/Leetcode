

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int numbers[2000] = {0};
    int i = 0, j = 0, k = 0;
    while(i<nums1Size && j<nums2Size){
        if(nums1[i]>=nums2[j]){
            numbers[k++] = nums2[j++];
        }else {
            numbers[k++] = nums1[i++];
        }
    }
    while(i<nums1Size){
        numbers[k++]=nums1[i++];
    }
    while(j<nums2Size){
        numbers[k++]=nums2[j++];
    }

    if(!((nums1Size+nums2Size)%2)) return (numbers[k/2]+numbers[k/2-1])/2.0;
    else return (numbers[(k-1)/2]);

}