char findTheDifference(char* s, char* t) {
    int arr[26] = {0};
    for(int i = 0; s[i] != '\0'; i++){
        arr[s[i] - 'a']++;
    }
    for(int i = 0; t[i] != '\0'; i++){
        arr[t[i] - 'a']--;
        if(arr[t[i] - 'a'] < 0){
            return t[i];
        }
    }
    return ' ';
}