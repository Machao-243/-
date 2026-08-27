int majorityElement(int* nums, int numsSize) {
    int ans = 0;
    int bleed = 0;
    for(int i = 0; i < numsSize; i++){
        int x = nums[i];
        if(bleed == 0){
            ans = x;
            bleed = 1;
        }else{
            if(ans == x){
                bleed++;
            }else{
                bleed--;
            }
        }
    }
    return ans;
}