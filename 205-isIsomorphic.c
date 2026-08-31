bool isIsomorphic(char* s, char* t) {
    int arr1[256] = {0};
    int arr2[256] = {0};
    int i = 0;
    while(s[i] != '\0'){
        char sc = s[i];
        char tc = t[i];
        if(arr1[sc] != arr2[tc]){
            return false;
        }
        arr1[sc] = i + 1;
        arr2[tc] = i + 1;
        i++;
    }
    return true;
}