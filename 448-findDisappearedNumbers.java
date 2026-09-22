class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        for(int num : nums){
            int index = (num - 1) % n;
            if(nums[index] <= n){
                nums[index] += n;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for(int i = 0; i < n; i++){
            if(nums[i] <= n){
                ans.add(i + 1);
            }
        }
        return ans;
    }
}