class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] arr = s.split(" ");
        if(pattern.length() != arr.length){
            return false;
        }
        Map<Object, Integer> map = new HashMap<>();
        for(Integer i = 0; i < arr.length; i++){
            if(map.put(pattern.charAt(i), i) != map.put(arr[i], i)){
                return false;
            }
        }
        return true;
    }
}