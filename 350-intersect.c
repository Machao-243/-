/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if(nums1Size > nums2Size){
        return intersect(nums2, nums2Size, nums1, nums1Size, returnSize);
    }
    int* arr = (int*)calloc(1001, sizeof(int));
    for(int i = 0; i < nums1Size; i++){
        arr[nums1[i]]++;
    }
    int* ans = (int*)calloc(nums1Size, sizeof(int));
    int index = 0;
    for(int i = 0; i < nums2Size; i++){
        if(arr[nums2[i]] > 0){
            ans[index++] = nums2[i];
            arr[nums2[i]]--;
        }
    }
    free(arr);
    *returnSize = index;
    return ans;
}