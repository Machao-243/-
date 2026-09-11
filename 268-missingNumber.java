//方法一：利用哈希表将数组中的元素存入，再从0到n过一遍集合，判断集合缺哪个元素，则为答案。
class Solution {
    public int missingNumber(int[] nums) {
        Set<Integer> set = new HashSet<Integer>();
        int len = nums.length;
        for(int i = 0; i < len; i++){
            set.add(nums[i]);
        }
        int missing = -1;
        for(int i = 0; i <= len; i++){
            if(!set.contains(i)){
                missing = i;
                break;
            }
        }
        return missing;
    }
}
//方法二：数学方法利用数列求出1到n的和，再遍历数组求出数组的和，两者做差。
int missingNumber(int* nums, int numsSize) {
    int n = numsSize;
    int total = (1 + n) * n / 2;
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    return total - sum;
}