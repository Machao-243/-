//快慢指针法，只要两个指针相遇那一定有环，在第一个重复元素相遇，判断那个元素是否是一。
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
//哈希表筛重。
class Solution {
    public boolean isHappy(int n) {
        Set<Integer> seen = new HashSet<>();
        while(n != 1 && !seen.contains(n)){
            seen.add(n);
            n = getNext(n);
        }
        return n == 1;
    }
    private int getNext(int n){
        int sum = 0;
        while(n > 0){
            int d = n % 10;
            sum += d * d;
            n = n / 10;
        }
        return sum;
    }
}