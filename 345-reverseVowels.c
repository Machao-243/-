char vowel[] = "aeiouAEIOU";
bool isVowel(char ch){
    for(int i = 0; vowel[i]; i++){
        if(ch == vowel[i]){
            return true;
        }
    }
    return false;
}
void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

char* reverseVowels(char* s) {
    int len = strlen(s);
    int left = 0;
    int right = len - 1;
    while(left < right){
        while(left < len && !isVowel(s[left])){
            left++;
        }
        while(right > 0 && !isVowel(s[right])){
            right--;
        }
        if(left < right){
            swap(&s[left], &s[right]);
            left++;
            right--;
        }
    }
    return s;
}