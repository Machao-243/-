bool isSubsequence(char* s, char* t) {
    int i = 0;
    int j = 0;
    int n = strlen(s);
    int m = strlen(t);
    while(i < n && j < m){
        if(s[i] == t[j]){
            i++;
        }
        j++;
    }
    return i == n;
}