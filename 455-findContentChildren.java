class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int m = g.length;
        int n = s.length;
        int count = 0;
        for(int i = 0, j = 0; i < m && j < n; i++, j++){
            while(j < n && g[i] > s[j]){
                j++;
            }
            if(j < n){
                count++;
            }
        }
        return count;
    }
}