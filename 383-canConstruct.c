bool canConstruct(char* ransomNote, char* magazine) {
    if(strlen(ransomNote) > strlen(magazine)){
        return false;
    }
    int arr[26] = {0};
    for(int i = 0; magazine[i] != '\0'; i++){
        char c = magazine[i];
        arr[c - 'a']++;
    }
    for(int i = 0; ransomNote[i] != '\0'; i++){
        char c = ransomNote[i];
        arr[c - 'a']--;
        if(arr[c - 'a'] < 0){
            return false;
        }
    }
    return true;
}