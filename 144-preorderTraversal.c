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
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(root == NULL){
        return NULL;
    }
    //申请一个一级指针来作为返回数组的地址，returnsize来控制数组的长度
    int* res = (int*)malloc(2000 * sizeof(int));
    //二级树指针 来表示一个栈 用来获取每一个树节点
    struct TreeNode** stack = (struct TreeNode**)malloc(2000 * sizeof(struct TreeNode*));
    //代表栈空
    int top = 0;
    //第一个树节点为根，top++
    stack[top++] = root;
    while(top > 0){
        //先top--,获取栈的树节点
        struct TreeNode* cur = stack[--top];
        //数组来接受值，数组大小自+
        res[(*returnSize)++] = cur -> val;
        //线序遍历头左右，栈后进先出，想让右子树进去
        if(cur -> right != NULL){
            stack[top++] = cur -> right;
        }
        if(cur -> left != NULL){
            stack[top++] = cur -> left;
        }
    }
    free(stack);
    return res;
} 