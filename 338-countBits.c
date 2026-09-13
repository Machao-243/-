/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count(int num){
    if(num == 0){
        return 0;
    }
    if(num % 2 == 0){
        return count(num / 2);
    }
    return count(num - 1) + 1;
}

int* countBits(int n, int* returnSize) {
    int* bits = malloc(sizeof(int) * (n + 1));
    *returnSize = n + 1;
    for(int i = 0; i <= n; i++){
        bits[i] = count(i);
    }
    return bits;
}