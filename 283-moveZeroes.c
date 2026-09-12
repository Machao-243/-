void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void moveZeroes(int* nums, int numsSize) {
    int left = 0;
    int right = 0;
    while(right < numsSize){
        if(nums[right]){
            swap(&nums[left], &nums[right]);
            left++;
        }
        right++;
    }
}