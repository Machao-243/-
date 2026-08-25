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
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(root == NULL){
        return NULL;
    }
    int* res = (int*)malloc(2000 * sizeof(int));
    struct TreeNode** stack = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    int top = 0;
    stack[top++] = root;
    while(top > 0){
        struct TreeNode* cur = stack[--top];
        res[(*returnSize)++] = cur -> val;
        if(cur -> left != NULL){
            stack[top++] = cur -> left;
        }
        if(cur -> right != NULL){
            stack[top++] = cur -> right;
        }
    }
    int a = 0;
    int b = (*returnSize) - 1;
    while(a < b){
        int temp = res[a];
        res[a] = res[b];
        res[b] = temp;
        a++;
        b--;
    }
    free(stack);
    return res;
}
