class Solution {
    public boolean isPalindrome(String s) {
        StringBuffer str = new StringBuffer();
        int length = s.length();
        for(int i = 0; i < length; i++){
            char c = s.charAt(i);
            if(Character.isLetterOrDigit(c)){
                str.append(Character.toLowerCase(c));
            }
        }
        int n = str.length();
        int left = 0;
        int right = n - 1;
        while(left < right){
            if(str.charAt(left) != str.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}