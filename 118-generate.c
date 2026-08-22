/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    //申请n个一维数组 作为二维数组
    int** ans = malloc(numRows * sizeof(int*));
    //数组的个数 取决于 numrows为多少
    (*returnSize) = numRows;
    //用来记录每一行的列数
    (*returnColumnSizes) = malloc(numRows * sizeof(int));

    for(int i = 0; i < numRows; i++){

        (*returnColumnSizes)[i] = i + 1;

        //每一行的数组
        ans[i] = malloc((i + 1) * sizeof(int));

        //解题思路
        ans[i][0] = ans[i][i] = 1;
        for(int j = 1; j < i; j++){
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }
    return ans;
}