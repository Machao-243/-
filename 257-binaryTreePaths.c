/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // top 为栈的长度
 void construct_paths(struct TreeNode* root, char** paths, int* returnSize, int* sta, int top){
    if(root != NULL){
        if(root -> left == NULL && root -> right == NULL){
            char* tmp = (char*) malloc(1001);
            int len = 0;
            for(int i = 0; i < top; i++){
                len += sprintf(tmp + len, "%d->", sta[i]);
            }
            sprintf(tmp + len, "%d", root -> val);
            paths[(*returnSize)++] = tmp;
        }else{
            sta[top++] = root -> val;
            construct_paths(root -> left, paths, returnSize, sta, top);
            construct_paths(root -> right, paths, returnSize, sta, top);
        }
    }
 }

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** paths = (char**) malloc(sizeof(char*) * 100);
    *returnSize = 0;
    int sta[1001];
    construct_paths(root, paths, returnSize, sta, 0);
    return paths;
}