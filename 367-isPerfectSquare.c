bool isPerfectSquare(int num) {
    int left = 0;
    int right = num;
    while(left <= right){
        int mid = left + (right - left) / 2;
        long square = (long) mid * mid;
        if(square < num){
            left = mid + 1;
        }else if(square > num){
            right = mid - 1;
        }else{
            return true;
        }
    }
    return false;
}