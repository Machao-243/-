class Solution {
    public int thirdMax(int[] nums) {
        TreeSet<Integer> s = new TreeSet<Integer>();
        for(int num : nums){
            s.add(num);
            if(s.size() > 3){
                s.remove(s.first());
            }
        }
        return s.size() == 3 ? s.first() : s.last();
    }
}