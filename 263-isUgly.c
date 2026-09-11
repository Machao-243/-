bool isUgly(int n) {
    if(n <= 0){
        return false;
    }
    int arr[] = {2, 3, 5};
    for(int i = 0; i < 3; i++){
        while(n % arr[i] == 0){
            n = n / arr[i];
        }
    }
    return n == 1;
}