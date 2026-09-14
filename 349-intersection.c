class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<Integer>();
        Set<Integer> set2 = new HashSet<Integer>();
        for(int i : nums1){
            set1.add(i);
        }
        for(int j : nums2){
            set2.add(j);
        }
        return getIntersection(set1, set2);
    }
    public int[] getIntersection(Set<Integer> set1, Set<Integer> set2){
        if(set1.size() > set2.size()){
            return getIntersection(set2, set1);
        }
        Set<Integer> set = new HashSet<Integer>();
        for(int num : set1){
            if(set2.contains(num)){
                set.add(num);
            }
        }
        int[] arr = new int[set.size()];
        int index = 0;
        for(int i : set){
            arr[index++] = i;
        }
        return arr;
    }
}