class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> po = new HashMap<Character, Integer>();
        int n = s.length();
        for(int i = 0; i < n; i++){
            char c = s.charAt(i);
            if(po.containsKey(c)){
                po.put(c, -1);
            }else{
                po.put(c, i);
            }
        }
        int first = n;
        for(Map.Entry<Character, Integer> entry : po.entrySet()){
            int value = entry.getValue();
            if(value != -1 && value < first){
                first = value;
            }
        }
        if(first == n){
            return -1;
        }
        return first;
    }
}