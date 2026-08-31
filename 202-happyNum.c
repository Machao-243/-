int getNext(int n){
    int sum = 0;
    while(n > 0){
        int d = n % 10;
        sum += d * d;
        n = n / 10;
    }
    return sum;
}

bool isHappy(int n) {
    int fastp = n;
    int slowp = n;
    do{
        slowp = getNext(slowp);
        fastp = getNext(fastp);
        fastp = getNext(fastp);
    }while(fastp != slowp);
    return slowp == 1;
}