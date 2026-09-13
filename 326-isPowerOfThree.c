bool isPowerOfThree(int n) {
    while(n && n % 3 == 0){
        n = n / 3;
    }
    return n == 1;
}