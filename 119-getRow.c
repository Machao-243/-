/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define MAX 34
 bool initialized;
 int c[MAX][MAX];
 void init(){
    if(initialized){
        return;
    }
    initialized = true;
    for(int i = 0; i < MAX; i++){
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++){
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
 }
int* getRow(int rowIndex, int* returnSize) {
    init();
    *returnSize = rowIndex + 1;
    return c[rowIndex];
}