int countSegments(char* s) {
    int count = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        if((i == 0 || s[i - 1] == ' ' ) && s[i] != ' '){
            count++;
        }
    }
    return count;
}   