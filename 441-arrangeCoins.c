int arrangeCoins(int n) {
    int left = 1;
    int right = n;
    while(left < right){
        int mid = left + (right - left + 1) / 2;
        if((long) mid * (1 + mid) <= (long)2 * n){
            left = mid;
        }else{
            right = mid - 1;
        }
    }
    return right;
}